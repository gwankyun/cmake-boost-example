#pragma once
#include <cstdint> // std::uint32_t
#include <cstring> // memset
#include <boost/asio/yield.hpp>

struct Header
{
    char sign[4];
    std::uint32_t length;
};

void initialize(Header& header)
{
    memset(header.sign, '@', sizeof(header.sign));
    header.length = 0;
}

#define DIS(...)

#define ASYNC_WRITE(socket_, data_, len_, per_, offset_, bytes_transferred_) \
    LOG(debug, "write begin"); \
    offset_ = 0; \
    do \
    { \
        yield socket_->async_write_some( \
            boost::asio::buffer( \
                (const char*)data_ + offset_, \
                std::min(len_ - offset_, (std::size_t)per_)), *this); \
        offset_ += bytes_transferred_; \
        if (false) \
        { \
            LOG(trace, "write: %1% offset_: %2%") % bytes_transferred_ % offset_; \
        } \
    } while (offset_ < len_); \
    LOG(debug, "write end");

#define ASYNC_READ(socket_, data_, len_, per_, offset_, bytes_transferred_) \
    LOG(debug, "read begin"); \
    offset_ = 0; \
    do \
    { \
        yield socket_->async_read_some( \
            boost::asio::buffer( \
                (char*)data_ + offset_, \
                std::min(len_ - offset_, (std::size_t)per_)), *this); \
        offset_ += bytes_transferred_; \
        if (false) \
        { \
            LOG(trace, "write: %1% offset_: %2%") % bytes_transferred_ % offset_; \
        } \
    } while (offset_ < len_); \
    LOG(debug, "read end");
