#ifndef BOOST_ALL_NO_LIB
#define BOOST_ALL_NO_LIB
#endif
#include <cstdint> // uint16_t
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include "server.h"
#include "log.hpp"
#include "option.h"
#include "compiler_detection.h"

void on_write(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer)
{
    if (error)
    {
        BLOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        auto remote_endpoint = socket->remote_endpoint();
        BLOG(debug, "close %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();
        return;
    }
    BLOG(debug, "bytes_transferred: %1%") % bytes_transferred;
    buffer->offset() += bytes_transferred;
    if (buffer->offset() < buffer->size())
    {
        socket->async_write_some(
            buffer->const_buffer(2),
            [socket, buffer](boost::system::error_code error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, buffer);
            });
    }
    else
    {
        BLOG(debug, "async_write_some finished");
        auto readBuffer = std::make_shared<Buffer>(1024);
        socket->async_read_some(
            buffer->mutable_buffer(),
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
        BLOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        auto remote_endpoint = socket->remote_endpoint();
        BLOG(debug, "close %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();
        return;
    }
    if (boost::ends_with(buffer->data(), "."))
    {
        BLOG(debug, "async_read_some: %1%") % buffer->data();
        auto writeBuffer = std::make_shared<Buffer>(std::string("server."));
        socket->async_write_some(
            writeBuffer->const_buffer(2),
            [socket, writeBuffer](boost::system::error_code error, std::size_t bytes_transferred)
            {
                on_write(error, bytes_transferred, socket, writeBuffer);
            });
    }
    else
    {
        buffer->offset() += bytes_transferred;
        socket->async_read_some(
            buffer->mutable_buffer(),
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
        BLOG(debug, "value: %1% message: %2%") % error.value() % error.message();
        return;
    }

    auto remote_endpoint = socket->remote_endpoint();
    BLOG(debug, "accept %1%:%2%") % remote_endpoint.address().to_string() % remote_endpoint.port();

    auto buffer = std::make_shared<Buffer>(1024);

    socket->async_read_some(
        buffer->mutable_buffer(),
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

class Option : public OptionBase
{
public:
    boost::optional<uint16_t> port;

    void parse(int argc, char* argv[], const filesystem::path& path) CXX_OVERRIDE
    {
        boost::program_options::options_description options_description;
        options_description.add_options()
            ("port", boost::program_options::value<uint16_t>())
            ;

        boost::program_options::variables_map variables_map;
        boost::program_options::store(
            boost::program_options::parse_command_line(argc, argv, options_description),
            variables_map);

        if (variables_map.count("port"))
        {
            port = boost::make_optional(variables_map["port"].as<uint16_t>());
        }

        if (!port)
        {
            if (filesystem::exists(path))
            {
                boost::property_tree::ptree ptree;
                boost::property_tree::read_xml(path.string(), ptree);
                port = ptree.get_optional<uint16_t>("option.port");
            }
        }
    }
};

int main(int argc, char* argv[])
{
    auto path = execution_path();
    BLOG(info, "execution path: %1%") % path.string();

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        BLOG(error, "Invalid port");
        return 1;
    }

    BLOG(info, "port: %1%") % (*option.port);

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
