#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/crc.hpp>
#include "asio/log.hpp"
#include "hex.hpp"

inline uint32_t crc(const void* data, std::size_t len)
{
    boost::crc_32_type crc_;
    crc_.process_bytes(data, len);
    return crc_.checksum();
}

int main()
{
    BOOST_LOG_TRIVIAL(info) << boost::filesystem::current_path();
    std::string str("hello world, Boost.");
    std::vector<std::string> result;
    boost::split(result, str, boost::is_any_of(" ,."), boost::token_compress_on);
    for (auto&& i : result)
    {
        BOOST_LOG_TRIVIAL(info) << i << " " << boost::to_upper_copy(i) << " " << boost::to_lower_copy(i);
    }

    LOG(info, "hex: %1%") % hex(str.begin(), str.end());
    LOG(info, "hex: %1%") % hex_n(str.begin(), str.size());

    boost::crc_32_type crc;
    crc.process_bytes(str.c_str(), str.size());
    LOG(info, "crc: %1%") % crc.checksum();
    //LOG(info, "crc: %1%") % boost::crc<32>(str.c_str(), str.size());
    return 0;
}