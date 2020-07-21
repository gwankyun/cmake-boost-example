#pragma once
#include <vector>
#include <cstddef> // std::size_t
#include <boost/asio/buffer.hpp>
#ifndef NOMINMAX
#define NOMINMAX
#endif // !NOMINMAX
#include <algorithm> // min copy_n
#include <string>

class Buffer
{
public:
    Buffer() : offset_(0)
    {
    }

    Buffer(std::size_t size)
        : vec_(size, '\0'), offset_(0)
    {
    }

    Buffer(const std::string& str)
        : offset_(0)
    {
        std::copy_n(str.c_str(), str.size(), std::back_inserter(vec_));
    }

    Buffer(const char* data, std::size_t len)
        : offset_(0)
    {
        std::copy_n(data, len, std::back_inserter(vec_));
    }

    ~Buffer()
    {
    }

    std::size_t size()
    {
        return vec_.size();
    }

    char* data()
    {
        return vec_.data();
    }

    std::size_t& offset()
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
    std::vector<char> vec_;
    std::size_t offset_;
};
