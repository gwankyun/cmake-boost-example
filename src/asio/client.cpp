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
#include "buffer.hpp"
#include "log.hpp"
#include "option.hpp"
#include "client.h"
#include "compiler_detection.h"
#include "data.h"

void on_read(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%", error.value(), error.message());
        auto remote_endpoint = socket->remote_endpoint();
        LOG(debug, "close %1%:%2%", remote_endpoint.address().to_string(), remote_endpoint.port());
        return;
    }

    buffer->offset() += bytes_transferred;

    Data data;

    if (unpack(*buffer, data))
    {
        LOG(debug, "async_read_some: %1%", data.message);
    }
    else
    {
        socket->async_read_some(
            buffer->read(),
            [socket, buffer](boost::system::error_code error, std::size_t bytes_transferred)
            {
                on_read(error, bytes_transferred, socket, buffer);
            });
    }
}

void on_write(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%", error.value(), error.message());
        auto remote_endpoint = socket->remote_endpoint();
        LOG(debug, "close %1%:%2%", remote_endpoint.address().to_string(), remote_endpoint.port());
        return;
    }
    //LOG(debug, "bytes_transferred: %1%") % bytes_transferred;
    buffer->offset() += bytes_transferred;
    if (buffer->offset() < buffer->size())
    {
        socket->async_write_some(
            buffer->read(2),
            [socket, buffer](boost::system::error_code error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, buffer);
            });
    }
    else
    {
        LOG(debug, "async_write_some finished");
        auto readBuffer = std::make_shared<Buffer>(1024);
        socket->async_read_some(
            buffer->read(),
            [socket, readBuffer](boost::system::error_code error,
                std::size_t bytes_transferred)
            {
                on_read(error, bytes_transferred, socket, readBuffer);
            });
    }
}

void on_connect(
    boost::system::error_code error,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%", error.value(), error.message());
        return;
    }
    auto remote_endpoint = socket->remote_endpoint();
    LOG(debug, "connect %1%:%2%", remote_endpoint.address().to_string(), remote_endpoint.port());

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
    LOG(info, "execution path: %1%", path.string());

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        LOG(error, "Invalid port");
        return 1;
    }

    if (!option.address)
    {
        LOG(error, "Invalid address");
        return 1;
    }

    LOG(info, "address: %1%", *option.address);
    LOG(info, "port: %1%", *option.port);

    boost::asio::io_context io_context;

    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        socket->async_connect(
            boost::asio::ip::tcp::endpoint(
                boost::asio::ip::make_address(*option.address),
                *option.port),
            [socket](boost::system::error_code error)
            {
                on_connect(error, socket);
            });
    }

    io_context.run();
    return 0;
}
