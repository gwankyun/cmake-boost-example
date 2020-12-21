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
#include "log.hpp"
#include "option.hpp"
#include "client.h"
#include "compiler_detection.h"
#include "data.h"
#include "socket.hpp"

class Client : public std::enable_shared_from_this<Client>
{
public:
    explicit Client(
        std::shared_ptr<boost::asio::ip::tcp::socket> socket_,
        std::string address_,
        std::uint16_t port_,
        boost::optional<std::uint32_t> timeout_
    )
        : socket(socket_), address(address_), port(port_)
        , timeout(timeout_)
    {
    }

    ~Client()
    {
    }

    void operator()(boost::system::error_code error = boost::system::error_code(), std::size_t bytes_transferred = 0);

private:
    std::shared_ptr<Data> data;
    std::string address;
    std::uint16_t port;
    boost::optional<std::uint32_t> timeout;
    boost::asio::coroutine coro;

    std::size_t offset = 0;
    std::shared_ptr<std::string> send;
    std::shared_ptr<Header> header;
    std::shared_ptr<std::vector<char>> recv;

    std::shared_ptr<boost::asio::ip::tcp::socket> socket;
    std::shared_ptr<boost::asio::steady_timer> timer;
};

void Client::operator()(boost::system::error_code error, std::size_t bytes_transferred)
{
    if (!error)
    {
        reenter(coro)
        {
            yield
            {
                timer.reset(new boost::asio::steady_timer(socket->get_executor(), boost::asio::chrono::seconds(3)));
                asyncWait(*socket, *timer, *this);
                asyncConnect(
                    *socket,
                    boost::asio::ip::tcp::endpoint(
                        boost::asio::ip::make_address(address),
                        port), *this);
            }
            timer->cancel();

            // async_write_some
            header.reset(new Header());
            initialize(*header);
            data.reset(new Data());
            data->message = "client.";
            send.reset(new std::string());
            pack(*data, *send);
            header->bodyLength = static_cast<uint32_t>(send->size());

            LOG(debug, "header: %1% data: %2%", sizeof(*header), header->bodyLength);

            offset = 0;
            do
            {
                yield
                {
                    timer.reset(new boost::asio::steady_timer(socket->get_executor(), boost::asio::chrono::seconds(3)));
                    asyncWait(*socket, *timer, *this);
                    asyncWrite(*socket, header.get(), sizeof(*header), offset, *this);
                }
                timer->cancel();
                offset += bytes_transferred;
            } while (offset < sizeof(*header));

            offset = 0;
            do
            {
                yield
                {
                    timer.reset(new boost::asio::steady_timer(socket->get_executor(), boost::asio::chrono::seconds(3)));
                    asyncWait(*socket, *timer, *this);
                    asyncWrite(*socket, send->c_str(), send->size(), offset, *this);
                }
                timer->cancel();
                offset += bytes_transferred;
            } while (offset < send->size());

            LOG(debug, "async_write_some finished");

            // async_read_some
            header.reset(new Header());

            offset = 0;
            do
            {
                yield
                {
                    timer.reset(new boost::asio::steady_timer(socket->get_executor(), boost::asio::chrono::seconds(3)));
                    asyncWait(*socket, *timer, *this);
                    asyncRead(*socket, header.get(), sizeof(*header), offset, *this);
                }
                timer->cancel();
                offset += bytes_transferred;
            } while (offset < sizeof(*header));

            recv.reset(new std::vector<char>(header->bodyLength + 1, '\0'));

            offset = 0;
            do
            {
                yield
                {
                    timer.reset(new boost::asio::steady_timer(socket->get_executor(), boost::asio::chrono::seconds(3)));
                    asyncWait(*socket, *timer, *this);
                    asyncRead(*socket, recv->data(), header->bodyLength, offset, *this);
                }
                timer->cancel();
                offset += bytes_transferred;
            } while (offset < header->bodyLength);

            data.reset(new Data());
            unpack(recv->data(), *data);

            LOG(info, "uuid: %1%", data->uuid);
            LOG(info, "message: %1%", data->message);
        }
    }
    else
    {
        LOG(error, "value: %1% message: %2%", error.value(), error.message());
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
        Client(socket, *option.address, *option.port, option.timeout)();
    }

    io_context.run();
    return 0;
}
