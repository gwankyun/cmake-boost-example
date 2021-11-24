#pragma once
#define BOOST_ASIO_NO_DEPRECATED 1
#include <cstddef> // std::size_t
#include <memory> // std::shared_ptr std::make_shared
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/error_code.hpp>
#include "buffer.hpp"

namespace asio = boost::asio;
using error_code_t = boost::system::error_code;
using socket_t = asio::ip::tcp::socket;

void on_read(
    error_code_t error,
    std::size_t bytes_transferred,
    std::shared_ptr<socket_t> socket,
    std::shared_ptr<Buffer> buffer);

void on_write(
    error_code_t error,
    std::size_t bytes_transferred,
    std::shared_ptr<socket_t> socket,
    std::shared_ptr<Buffer> buffer);

void on_connect(
    error_code_t error,
    std::shared_ptr<socket_t> socket);
