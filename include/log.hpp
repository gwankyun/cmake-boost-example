#pragma once
#include <sstream>
#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

#define BOOST_DISABLE_CURRENT_LOCATION 
#include <boost/assert/source_location.hpp>

#undef BOOST_CURRENT_LOCATION
#define BOOST_CURRENT_LOCATION \
  ::boost::source_location(__FILE__, __LINE__, __func__)

inline std::string current(const boost::source_location& location)
{
    return (boost::format("[%-9s:%4d] ") % std::string(location.function_name()).substr(0, 9) % location.line()).str();
}

template<typename T>
inline std::string to_string(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

#ifndef LOG
#  define LOG(_lvl) BOOST_LOG_TRIVIAL(_lvl) << current(BOOST_CURRENT_LOCATION)
#endif

#ifndef LOG_FORMAT
#  define LOG_FORMAT(_lvl, _fmt) LOG(_lvl) << boost::format(_fmt)
#endif

#ifndef TO_STRING_IMPL
#  define TO_STRING_IMPL(x) #x
#endif

#ifndef TO_STRING
#  define TO_STRING(x) TO_STRING_IMPL(x)
#endif

#ifndef LOG_DBG
#  define LOG_DBG(_lvl, _value) LOG(_lvl) << TO_STRING(_value) << ": " << to_string(_value)
#endif
