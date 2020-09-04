#pragma once
#include <cstdint> // std::uint32_t
#include <cstring> // memset
#include <boost/asio/yield.hpp>

struct Header
{
    char sign[4]; // 4個@表示包頭
    std::uint16_t headerLength; // 包頭長
    std::uint16_t headerType; // 包頭類型，默認0，為拓展而留
    std::uint32_t headerChecksum; // 包頭校驗和
    std::uint32_t bodyLength; // 包體長
    std::uint16_t bodyMajorType; // 包體主類型，和bodyMinorType配合標識包體的數據類型
    std::uint16_t bodyMinorType; // 包體次類型
    std::uint32_t bodyChecksum; // 包頭校驗和
};

inline void initialize(Header& header)
{
    memset(header.sign, '@', sizeof(header.sign));
    header.headerLength = sizeof(header);
    header.headerType = 0;
    header.headerChecksum = 0;
    header.bodyLength = 0;
    header.bodyMajorType = 0;
    header.bodyMinorType = 0;
    header.bodyChecksum = 0;
}

#define ASYNC_WRITE(socket_, data_, len_, per_, offset_, bytes_transferred_) \
    offset_ = 0; \
    do \
    { \
        yield socket_->async_write_some( \
            boost::asio::buffer( \
                (const char*)data_ + offset_, \
                std::min(len_ - offset_, (std::size_t)per_)), *this); \
        offset_ += bytes_transferred_; \
    } while (offset_ < len_);

#define ASYNC_READ(socket_, data_, len_, per_, offset_, bytes_transferred_) \
    offset_ = 0; \
    do \
    { \
        yield socket_->async_read_some( \
            boost::asio::buffer( \
                (char*)data_ + offset_, \
                std::min(len_ - offset_, (std::size_t)per_)), *this); \
        offset_ += bytes_transferred_; \
    } while (offset_ < len_);
