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

    void operator()(boost::system::error_code error = boost::system::error_code(), std::size_t bytes_transferred = 0);

private:
    boost::asio::ip::tcp::acceptor& acceptor;
    std::shared_ptr<boost::asio::ip::tcp::socket> socket;
    std::shared_ptr<Data> data;
    boost::asio::coroutine coro;

    std::size_t offset = 0;
    std::shared_ptr<std::string> send;
    std::shared_ptr<Header> header;
    std::shared_ptr<std::vector<char>> recv;
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

            ASYNC_READ(socket, header.get(), sizeof(*header), 3, offset, bytes_transferred);
            LOG(debug, "lenght: %1%") % header->bodyLength;

            recv.reset(new std::vector<char>(header->bodyLength + 1, '\0'));
            ASYNC_READ(socket, recv->data(), header->bodyLength, 3, offset, bytes_transferred);

            data.reset(new Data());
            unpack(recv->data(), *data);

            LOG(info, "uuid: %1%") % data->uuid;
            LOG(info, "message: %1%") % data->message;

            // async_write_some
            header.reset(new Header());
            initialize(*header);
            data.reset(new Data());
            data->message = "server.";
            send.reset(new std::string());
            pack(*data, *send);
            header->bodyLength = static_cast<uint32_t>(send->size());

            ASYNC_WRITE(socket, header.get(), sizeof(*header), 3, offset, bytes_transferred);

            ASYNC_WRITE(socket, send->c_str(), send->size(), 3, offset, bytes_transferred);

            LOG(debug, "async_write_some finished");

            //socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both, error);
        }
    }
    else
    {
        LOG(error, "value: %1% message: %2%") % error.value() % error.message();
    }
}

filesystem::path execution_path()
{
    char fileName[MAX_PATH] = { '\0' };
    GetModuleFileNameA(NULL, fileName, sizeof(fileName));
    filesystem::path path(fileName);
    return path.parent_path();
}

//BOOST_LOG_ATTRIBUTE_KEYWORD(severity, "Severity", severity_level)

int main(int argc, char* argv[])
{
    //boost::log::core::get()->set_filter
    //(
    //    boost::log::trivial::severity >= boost::log::trivial::info
    //);
    //boost::log::core::get()->set_filter(severity >= warning);
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

    //LOG_IF(true, info, "%1%") % "yes";

    boost::asio::io_context io_context;

    boost::asio::ip::tcp::acceptor acceptor(
        io_context,
        boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), *option.port));

    {
        auto socket = std::make_shared<boost::asio::ip::tcp::socket>(io_context);
        Server(acceptor, socket)();
    }

    io_context.run();
    return 0;
}
