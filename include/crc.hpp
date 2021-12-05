#pragma once
#include <cstdint> // std::uint32_t
#include <boost/crc.hpp> // boost::crc_32_type

inline std::uint32_t crc32(boost::crc_32_type& crc, const void* data, std::size_t length)
{
    crc.process_bytes(data, length);
    return crc.checksum();
}

inline std::uint32_t crc32(const void* data, std::size_t length)
{
    boost::crc_32_type crc;
    return crc32(crc, data, length);
}
