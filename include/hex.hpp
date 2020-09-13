#pragma once
#include <iterator>
#include <boost/algorithm/hex.hpp>

template<typename First, typename Last>
inline std::string hex(First first, Last last)
{
    std::string result;
    boost::algorithm::hex(first, last, std::back_inserter(result));
    return result;
}

template<typename First>
inline std::string hex_n(First first, std::size_t n)
{
    std::string result;
    boost::algorithm::hex(first, first + n, std::back_inserter(result));
    return result;
}
