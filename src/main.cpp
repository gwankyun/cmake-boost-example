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

    LOG(info, "hex: %1%", hex(str.begin(), str.end()));
    LOG(info, "hex: %1%", hex_n(str.begin(), str.size()));

    boost::crc_32_type crc;
    crc.process_bytes(str.c_str(), str.size());
    LOG(info, "crc: %1%", crc.checksum());
    LOG(info, "log: %1%", 1);
    LOG(info, "log: %1% %2%", 1, 2);
    LOG(info, "log: %1% %2% %3%", 1, 2, 3);
    LOG(info, "log: %1% %2% %3% %4%", 1, 2, 3, 4);
    LOG(info, "log: %1% %2% %3% %4% %5%", 1, 2, 3, 4, 5);
    LOG(info, "log: %1% %2% %3% %4% %5% %6%", 1, 2, 3, 4, 5, 6);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7%", 1, 2, 3, 4, 5, 6, 7);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7% %8%", 1, 2, 3, 4, 5, 6, 7, 8);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7% %8% %9%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    LOG(info, 2);
    LOG(info);
    return 0;
}