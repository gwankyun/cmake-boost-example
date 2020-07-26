#ifndef BOOST_ALL_NO_LIB
#define BOOST_ALL_NO_LIB
#endif
#include <cstdint> // std::uint16_t std::uint32_t
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/coroutine.hpp>
#include <boost/asio/yield.hpp>
#include <boost/system/error_code.hpp>
#include "log.hpp"
#include "option.hpp"
#include "compiler_detection.h"
#include "data.h"

class Server : boost::asio::coroutine
{
public:
    explicit Server(
        std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor_,
        std::shared_ptr<boost::asio::ip::tcp::socket> socket_
    )
        : acceptor(acceptor_), socket(socket_)
    {
    }

    ~Server()
    {
    }

    void operator()(boost::system::error_code ec = boost::system::error_code(), std::size_t length = 0);

private:
    std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor;
    std::shared_ptr<boost::asio::ip::tcp::socket> socket;
    std::shared_ptr<Buffer> buffer;
    std::shared_ptr<Data> data;
};

void Server::operator()(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
    {
        reenter(this)
        {
            // async_accept
            do
            {
                socket.reset(new boost::asio::ip::tcp::socket(acceptor->get_executor()));
                yield acceptor->async_accept(*socket, *this);
                fork Server(*this)();
            } while (is_parent());

            // async_read_some
            buffer.reset(new Buffer(1024));
            data.reset(new Data());
            do
            {
                yield socket->async_read_some(buffer->mutable_buffer(), *this);
                buffer->offset() += length;
            } while (!unpack(*buffer, *data));
            BLOG(info, "uuid: %1%") % data->uuid;
            BLOG(info, "message: %1%") % data->message;

            // async_write_some
            data.reset(new Data());
            data->message = "server.";
            buffer.reset(new Buffer());
            pack(*data, *buffer);
            do
            {
                yield socket->async_write_some(buffer->const_buffer(2), *this);
                buffer->offset() += length;
            } while (buffer->offset() < buffer->size());
            BLOG(debug, "async_write_some finished");

            //socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
        }
    }
    else
    {
        BLOG(debug, "value: %1% message: %2%") % ec.value() % ec.message();
    }
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

    auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
    Server(acceptor, socket)();

    io_context.run();
    return 0;
}
#include <boost/asio/yield.hpp>
