#pragma once
#include <vector>
#include <cstddef> // std::size_t std::byte
#define BOOST_ASIO_NO_DEPRECATED 1
#include <boost/asio/buffer.hpp>
#ifndef NOMINMAX
#define NOMINMAX
#endif // !NOMINMAX
#include <algorithm> // std::min std::copy_n
#include <string>

class Buffer
{
public:

#ifdef __cpp_lib_byte
    using value_type = std::byte;
#else
    using value_type = char;
#endif // __cpp_lib_byte

    Buffer() : offset_(0)
    {
    }

    Buffer(std::size_t size)
        : vec_(size), offset_(0)
    {
    }

    Buffer(const std::string& str)
        : offset_(0)
    {
        std::copy_n(reinterpret_cast<const value_type*>(str.c_str()), str.size(), std::back_inserter(vec_));
    }

    Buffer(const char* data, std::size_t len)
        : offset_(0)
    {
        std::copy_n(reinterpret_cast<const value_type*>(data), len, std::back_inserter(vec_));
    }

    ~Buffer()
    {
    }

    template<typename T>
    void append(const T& value)
    {
        std::copy_n(reinterpret_cast<const value_type*>(&value), sizeof(value), std::back_inserter(vec_));
    }

    void append(const std::string& str)
    {
        std::copy_n(reinterpret_cast<const value_type*>(str.c_str()), str.size(), std::back_inserter(vec_));
    }

    std::size_t size() const
    {
        return vec_.size();
    }

    std::size_t size()
    {
        return vec_.size();
    }

    value_type* data() const
    {
        return const_cast<value_type*>(vec_.data());
    }

    std::size_t& offset()
    {
        return offset_;
    }

    std::size_t offset() const
    {
        return offset_;
    }

    boost::asio::mutable_buffer mutable_buffer()
    {
        return boost::asio::buffer(data() + offset(), size() - offset());
    }

    boost::asio::const_buffer const_buffer()
    {
        return boost::asio::buffer(data() + offset(), size() - offset());
    }

    boost::asio::mutable_buffer mutable_buffer(std::size_t count)
    {
        return boost::asio::buffer(
            data() + offset(),
            std::min(size() - offset(), count));
    }

    boost::asio::const_buffer const_buffer(std::size_t count)
    {
        return boost::asio::buffer(
            data() + offset(),
            std::min(size() - offset(), count));
    }

private:
    std::vector<value_type> vec_;
    std::size_t offset_;
};
