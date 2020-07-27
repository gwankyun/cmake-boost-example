#ifndef BOOST_ALL_NO_LIB
#define BOOST_ALL_NO_LIB
#endif
#include <cstdint> // std::uint16_t std::uint32_t
#include <cstddef> // std::size_t
#include <string>
#define BOOST_ASIO_NO_DEPRECATED 1
#include <memory> // std::shared_ptr std::make_shared
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/error_code.hpp>
#include "buffer.hpp"
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/optional.hpp>
#include <boost/program_options.hpp>
#include <boost/asio/coroutine.hpp>
#include <boost/asio/yield.hpp>
#include "buffer.hpp"
#include "log.hpp"
#include "option.hpp"
#include "client.h"
#include "compiler_detection.h"
#include "data.h"

class Client
{
public:
    explicit Client(
        std::shared_ptr<boost::asio::ip::tcp::socket> socket_,
        std::string address_,
        std::uint16_t port_
    )
        : socket(socket_), address(address_), port(port_)
    {
    }

    ~Client()
    {
    }

    void operator()(boost::system::error_code ec = boost::system::error_code(), std::size_t length = 0);

private:
    std::shared_ptr<boost::asio::ip::tcp::socket> socket;
    std::shared_ptr<Buffer> buffer;
    std::shared_ptr<Data> data;
    std::string address;
    std::uint16_t port;
    boost::asio::coroutine coro;
};

void Client::operator()(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
    {
        reenter(coro)
        {
            yield socket->async_connect(
                boost::asio::ip::tcp::endpoint(
                    boost::asio::ip::make_address(address),
                    port), *this);

            buffer.reset(new Buffer());
            data.reset(new Data());
            data->message = "client.";
            pack(*data, *buffer);
            do
            {
                yield socket->async_write_some(buffer->write(2), *this);
                buffer->offset() += length;
            } while (buffer->offset() < buffer->size());
            BLOG(debug, "async_write_some finished");

            buffer.reset(new Buffer(2));
            data.reset(new Data());
            do
            {
                yield socket->async_read_some(buffer->read(2), *this);
                buffer->offset() += length;
            } while (!unpack(*buffer, *data));
            BLOG(info, "uuid: %1%") % data->uuid;
            BLOG(info, "message: %1%") % data->message;
        }
    }
    else
    {
        BLOG(error, "value: %1% message: %2%") % ec.value() % ec.message();
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

    if (!option.address)
    {
        BLOG(error, "Invalid address");
        return 1;
    }

    BLOG(info, "address: %1%") % (*option.address);
    BLOG(info, "port: %1%") % (*option.port);

    boost::asio::io_context io_context;

    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        Client(socket, *option.address, *option.port)();
    }

    io_context.run();
    return 0;
}
