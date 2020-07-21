#ifndef BOOST_ALL_NO_LIB
#define BOOST_ALL_NO_LIB
#endif
#include <iostream>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/algorithm/string.hpp>

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
    return 0;
}