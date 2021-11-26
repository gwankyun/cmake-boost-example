#include <cstdint> // std::uint16_t std::uint32_t
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include "common.h"
#include "server.h"
#include "option.hpp"

using acceptor_t = asio::ip::tcp::acceptor;

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
        LOG_FORMAT(info, "uuid: %1%") % data.uuid;
        LOG_FORMAT(info, "message: %1%") % data.message;
        auto writeBuffer = std::make_shared<Buffer>();
        Data writeData;
        writeData.message = "server.";
        pack(writeData, *writeBuffer);

        socket->async_write_some(
            writeBuffer->write(2),
            [socket, writeBuffer](error_code_t error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, writeBuffer);
            });
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

void on_accept(
    error_code_t error,
    std::shared_ptr<acceptor_t> acceptor,
    std::shared_ptr<socket_t> socket)
{
    if (error)
    {
        LOG_DBG(error, error);
        return;
    }

    auto remote_endpoint = socket->remote_endpoint();
    LOG_DBG(debug, remote_endpoint);

    auto buffer = std::make_shared<Buffer>(1024);

    socket->async_read_some(
        buffer->read(),
        [socket, buffer](error_code_t error, std::size_t bytes_transferred)
        {
            on_read(error, bytes_transferred, socket, buffer);
        });

    auto newSocket = std::make_shared<socket_t>(acceptor->get_executor());
    acceptor->async_accept(
        *newSocket,
        [acceptor, newSocket](error_code_t error)
        {
            on_accept(error, acceptor, newSocket);
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
    LOG_FORMAT(info, "execution path: %1%") % path.string();

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        LOG_FORMAT(error, "Invalid port");
        return 1;
    }
    auto port = *option.port;

    LOG_DBG(info, port);

    asio::io_context io_context;

    auto acceptor = std::make_shared<acceptor_t>(
        io_context,
        asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));

    {
        auto socket = std::make_shared<socket_t>(io_context);
        acceptor->async_accept(
            *socket,
            [acceptor, socket](error_code_t error)
            {
                on_accept(error, acceptor, socket);
            });
    }

    io_context.run();
    return 0;
}
