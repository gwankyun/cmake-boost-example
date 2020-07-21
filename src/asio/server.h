#pragma once
#define BOOST_ASIO_NO_DEPRECATED 1
#include <cstddef> // size_t
#include <memory> // shared_ptr make_shared
#include <boost/asio/ip/tcp.hpp>
#include <boost/system/error_code.hpp>
#include "buffer.hpp"

void on_read(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer);

void on_write(
    boost::system::error_code error,
    std::size_t bytes_transferred,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket,
    std::shared_ptr<Buffer> buffer);

void on_accept(
    boost::system::error_code error,
    std::shared_ptr<boost::asio::ip::tcp::acceptor> acceptor,
    std::shared_ptr<boost::asio::ip::tcp::socket> socket);
