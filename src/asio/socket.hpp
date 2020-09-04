#pragma once
#include <cstdint> // std::uint32_t
#include <cstring> // memset
#include <boost/asio/yield.hpp>

struct Header
{
    char sign[4]; // 4��@��ʾ���^
    std::uint16_t headerLength; // ���^�L
    std::uint16_t headerType; // ���^��ͣ�Ĭ�J0������չ����
    std::uint32_t headerChecksum; // ���^У��
    std::uint32_t bodyLength; // ���w�L
    std::uint16_t bodyMajorType; // ���w����ͣ���bodyMinorType��Ϙ��R���w�Ĕ������
    std::uint16_t bodyMinorType; // ���w�����
    std::uint32_t bodyChecksum; // ���^У��
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
