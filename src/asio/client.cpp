#include <cstdint> // std::uint16_t std::uint32_t
#include <string>
#define BOOST_ASIO_NO_DEPRECATED 1
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <log.hpp>
#include "buffer.hpp"
#include "option.hpp"
#include "client.h"
#include "data.h"

namespace asio = boost::asio;
using error_code_t = boost::system::error_code;
using socket_t = asio::ip::tcp::socket;

template<>
inline std::string to_string(error_code_t error)
{
    return (boost::format("{ value: %1% message: %2% }") % error.value() % error.message()).str();
}

template<>
inline std::string to_string(asio::ip::tcp::endpoint remote_endpoint)
{
    return (boost::format("{ %1%:%2% }") % remote_endpoint.address().to_string() % remote_endpoint.port()).str();
}

inline void on_error(error_code_t error, const socket_t& socket)
{
    LOG_DBG(error, error);
    auto remote_endpoint = socket.remote_endpoint();
    LOG_DBG(error, remote_endpoint);
}

void on_read(
    error_code_t error,
    std::size_t bytes_transferred,
    std::shared_ptr<socket_t> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        on_error(error, *socket);
        return;
    }

    buffer->offset() += bytes_transferred;

    Data data;

    auto state = unpack(*buffer, data);
    if (state == DataState::Full)
    {
        LOG_FORMAT(debug, "async_read_some: %1%") % data.message;
    }
    else if (state == DataState::Part)
    {
        socket->async_read_some(
            buffer->read(),
            [socket, buffer](error_code_t error, std::size_t bytes_transferred)
            {
                on_read(error, bytes_transferred, socket, buffer);
            });
    }
    else
    {
        LOG_FORMAT(error, "unpack error!");
    }
}

void on_write(
    error_code_t error,
    std::size_t bytes_transferred,
    std::shared_ptr<socket_t> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        on_error(error, *socket);
        return;
    }
    LOG_FORMAT(debug, "bytes_transferred: %1%") % bytes_transferred;
    buffer->offset() += bytes_transferred;
    if (buffer->offset() < buffer->size())
    {
        socket->async_write_some(
            buffer->write(2),
            [socket, buffer](error_code_t error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, buffer);
            });
    }
    else
    {
        LOG_FORMAT(debug, "async_write_some finished");
        auto readBuffer = std::make_shared<Buffer>(1024);
        socket->async_read_some(
            buffer->read(),
            [socket, readBuffer](error_code_t error,
                std::size_t bytes_transferred)
            {
                on_read(error, bytes_transferred, socket, readBuffer);
            });
    }
}

void on_connect(
    error_code_t error,
    std::shared_ptr<socket_t> socket)
{
    if (error)
    {
        LOG_DBG(error, error);
        return;
    }
    auto remote_endpoint = socket->remote_endpoint();
    LOG_DBG(debug, remote_endpoint);

    auto buffer = std::make_shared<Buffer>();
    Data data;
    data.message = "client.";
    pack(data, *buffer);

    socket->async_write_some(
        buffer->write(2),
        [socket, buffer](boost::system::error_code error, std::size_t bytes_transferred)
        {
            on_write(error, bytes_transferred, socket, buffer);
        });
}

filesystem::path execution_path()
{
    char fileName[MAX_PATH] = { '\0' };
    GetModuleFileNameA(NULL, fileName, sizeof(fileName));
    filesystem::path path(fileName);
    return path.parent_path();
}

int main(int argc, char* argv[])
{
    auto path = execution_path();
    LOG_DBG(info, path);

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        LOG_FORMAT(error, "Invalid port");
        return 1;
    }
    auto port = *option.port;

    if (!option.address)
    {
        LOG_FORMAT(error, "Invalid address");
        return 1;
    }
    auto address = *option.address;

    LOG_DBG(info, address);
    LOG_DBG(info, port);

    asio::io_context io_context;

    {
        auto socket = std::make_shared<socket_t>(io_context);
        socket->async_connect(
            asio::ip::tcp::endpoint(
                asio::ip::make_address(address),
                port),
            [socket](error_code_t error)
            {
                on_connect(error, socket);
            });
    }

    io_context.run();
    return 0;
}
