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
#include "socket.hpp"

enum struct OperatorType
{
    Socket = 1,
    Timer
};

class Server
{
public:
    explicit Server(
        boost::asio::ip::tcp::acceptor& acceptor_,
        std::shared_ptr<boost::asio::ip::tcp::socket> socket_
    )
        : acceptor(acceptor_), socket(socket_)
    {
    }

    ~Server()
    {
    }

    void async_wait(std::function<void(boost::system::error_code, std::size_t)> handler)
    {
        timer->async_wait([handler](boost::system::error_code error_code)
            {
                handler(error_code, 0);
            });
    }

    void operator()(boost::system::error_code error = boost::system::error_code(), std::size_t bytes_transferred = 0);

    //std::shared_ptr<bool> isTimer;

    void stopTimer()
    {
        LOG(debug, "");
        //*isTimer = false;
        timer->cancel();
    }

    std::shared_ptr<boost::asio::steady_timer> timer;
    std::shared_ptr<boost::asio::ip::tcp::socket> socket;

private:
    boost::asio::ip::tcp::acceptor& acceptor;
    std::shared_ptr<Data> data;
    boost::asio::coroutine coro;

    std::size_t offset = 0;
    std::shared_ptr<std::string> send;
    std::shared_ptr<Header> header;
    std::shared_ptr<std::vector<char>> recv;

    //boost::asio::io_context& io_context;
    OperatorType type;
    int flag = 0;
};

void Server::operator()(boost::system::error_code error, std::size_t bytes_transferred)
{
    if (!error)
    {
        reenter(coro)
        {
            // async_accept
            do
            {
                socket.reset(new boost::asio::ip::tcp::socket(acceptor.get_executor()));
                yield acceptor.async_accept(*socket, *this);
                fork Server(*this)();
            } while (coro.is_parent());

            // async_read_some
            header.reset(new Header());
            offset = 0;
            do
            {
                yield
                {
                    asyncWait(*socket, boost::asio::chrono::seconds(3), *this);
                    asyncRead(*socket, header.get(), sizeof(*header), offset, *this);
                }
                stopTimer();
                offset += bytes_transferred;
            } while (offset < sizeof(*header));

            LOG(debug, "length: %1%", header->bodyLength);

            recv.reset(new std::vector<char>(header->bodyLength + 1, '\0'));
            offset = 0;
            do
            {
                yield
                {
                    asyncWait(*socket, boost::asio::chrono::seconds(3), *this);
                    asyncRead(*socket, recv->data(), header->bodyLength, offset, *this);
                }
                stopTimer();
                offset += bytes_transferred;
            } while (offset < header->bodyLength);

            data.reset(new Data());
            unpack(recv->data(), *data);

            LOG(info, "uuid: %1%", data->uuid);
            LOG(info, "message: %1%", data->message);

            // async_write_some
            header.reset(new Header());
            initialize(*header);
            data.reset(new Data());
            data->message = "server.";
            send.reset(new std::string());
            pack(*data, *send);
            header->bodyLength = static_cast<uint32_t>(send->size());

            offset = 0;
            do
            {
                yield
                {
                    asyncWait(*socket, boost::asio::chrono::seconds(3), *this);
                    asyncWrite(*socket, header.get(), sizeof(*header), offset, *this);
                }
                stopTimer();
                offset += bytes_transferred;
            } while (offset < sizeof(*header));

            offset = 0;
            do
            {
                yield
                {
                    asyncWait(*socket, boost::asio::chrono::seconds(3), *this);
                    asyncWrite(*socket, send->c_str(), send->size(), offset, *this);
                }
                stopTimer();
                offset += bytes_transferred;
            } while (offset < send->size());

            LOG(debug, "async_write_some finished");

            //socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both, error);
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

void on_wait(boost::system::error_code error_code, std::shared_ptr<boost::asio::steady_timer> timer)
{
    if (error_code)
    {
        LOG(info, "%1%", error_code.message());
    }
    LOG(info, "timer out");
    auto new_timer = std::make_shared<boost::asio::steady_timer>(timer->get_executor(), boost::asio::chrono::seconds(1));
    new_timer->async_wait([new_timer](boost::system::error_code error_code)
        {
            on_wait(error_code, new_timer);
        });
}

class Timer
{
public:
    Timer(boost::asio::io_context& io_context_)
        : io_context(io_context_)
    {
    }

    ~Timer()
    {
    }

    void operator()(boost::system::error_code error = boost::system::error_code());

private:
    boost::asio::coroutine coro;
    boost::asio::io_context& io_context;
    std::shared_ptr<boost::asio::steady_timer> timer;
};

void Timer::operator()(boost::system::error_code error)
{

    if (!error)
    {
        reenter(coro)
        {
            do
            {
                timer.reset(new boost::asio::steady_timer(io_context, boost::asio::chrono::seconds(1)));
                yield timer->async_wait(*this);
                LOG(info, "timer out");
                fork Timer(*this)();
            } while (coro.is_parent());
        }
    }
}

int main(int argc, char* argv[])
{
    LOG(info, "");
    LOG(info, "start");
    auto path = execution_path();
    LOG(info, "execution path: %1%", path.string());

    Option option;
    option.parse(argc, argv, path.parent_path().parent_path() / "asio.xml");

    if (!option.port)
    {
        LOG(error, "Invalid port");
        return 1;
    }

    LOG(info, "port: %1%", *option.port);

    boost::asio::io_context io_context;

    boost::asio::ip::tcp::acceptor acceptor(
        io_context,
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), *option.port));

    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        //Server(acceptor, socket)();
        auto server = std::make_shared<Server>(acceptor, socket);
        (*server)();
    }

    {
        //auto timer = std::make_shared<boost::asio::steady_timer>(io_context, boost::asio::chrono::seconds(1));
        //timer->async_wait([timer](boost::system::error_code error_code)
        //    {
        //        on_wait(error_code, timer);
        //    });
    }

    {
        //auto timer = std::make_shared<Timer>(io_context);
        //(*timer)();
    }

    io_context.run();
    return 0;
}
