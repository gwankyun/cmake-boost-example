#include <cstdint> // std::uint16_t std::uint32_t
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include "server.h"
#include "log.hpp"
#include "option.hpp"
#include "compiler_detection.h"
#include "data.h"

void on_write(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        auto remote_endpoint = socket->remote_endpoint();
        LOG(debug, "close %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();
        return;
    }
    //LOG(debug, "bytes_transferred: %1%") % bytes_transferred;
    buffer->offset() += bytes_transferred;
    if (buffer->offset() < buffer->size())
    {
        socket->async_write_some(
            buffer->write(2),
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

void on_read(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        auto remote_endpoint = socket->remote_endpoint();
        LOG(debug, "close %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();
        return;
    }

    buffer->offset() += bytes_transferred;

    Data data;

    if (unpack(*buffer, data))
    {
        LOG(info, "uuid: %1%") % data.uuid;
        LOG(info, "message: %1%") % data.message;
        auto writeBuffer = std::make_shared<Buffer>();
        Data writeData;
        writeData.message = "server.";
        pack(writeData, *writeBuffer);

        socket->async_write_some(
            writeBuffer->write(2),
            [socket, writeBuffer](boost::system::error_code error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, writeBuffer);
            });
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

void on_accept(
    boost::system::error_code error,
    std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket)
{
    if (error)
    {
        LOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        return;
    }

    auto remote_endpoint = socket->remote_endpoint();
    LOG(debug, "accept %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();

    auto buffer = std::make_shared<Buffer>(1024);

    socket->async_read_some(
        buffer->read(),
        [socket, buffer](boost::system::error_code error, std::size_t bytes_transferred)
        {
            on_read(error, bytes_transferred, socket, buffer);
        });

    auto newSocket = std::make_shared<boost::asio::ip::tcp::socket>(acceptor->get_executor());
    acceptor->async_accept(*newSocket,
        [acceptor, newSocket](boost::system::error_code error)
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
    LOG(info, "execution path: %1%") % path.string();

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        LOG(error, "Invalid port");
        return 1;
    }

    LOG(info, "port: %1%") % (*option.port);

    boost::asio::io_context io_context;

    auto acceptor = std::make_shared<boost::asio::ip::tcp::acceptor>(
        io_context,
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), *option.port));

    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        acceptor->async_accept(*socket,
            [acceptor, socket](boost::system::error_code error)
            {
                on_accept(error, acceptor, socket);
            });
    }

    io_context.run();
    return 0;
}
