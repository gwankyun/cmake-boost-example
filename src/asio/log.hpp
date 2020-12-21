#pragma once
#include <string>
#include <fstream>
#include <boost/log/trivial.hpp>
#include <boost/format.hpp>
#include <boost/preprocessor.hpp>

#ifndef BOOST_PP_REPEAT_Z
#  define BOOST_PP_REPEAT_Z(z) BOOST_PP_REPEAT_##z
#endif // !BOOST_PP_REPEAT_Z

#ifndef BOOST_PP_REPEAT_FROM_TO_Z
#  define BOOST_PP_REPEAT_FROM_TO_Z(z) BOOST_PP_REPEAT_FROM_TO_##z
#endif // !BOOST_PP_REPEAT_FROM_TO_Z

#ifndef BOOST_TYPENAME
#  define BOOST_TYPENAME(z, n, x) BOOST_PP_COMMA_IF(n) typename x##n
#endif // !BOOST_TYPENAME

#ifndef BOOST_PARAMETER
#  define BOOST_PARAMETER(z, n, x) BOOST_PP_COMMA_IF(n) x##n x##n##_
#endif // !BOOST_PARAMETER

#ifndef BOOST_ARGUMENT
#  define BOOST_ARGUMENT(z, n, x) % x##n##_
#endif // !BOOST_ARGUMENT

#ifndef REPEAT_BLOG
#  define REPEAT_BLOG(z, n, _) \
    template<BOOST_PP_REPEAT_Z(z)(n, BOOST_TYPENAME, T)> \
    inline void blog(boost::log::trivial::severity_level level, std::string info, std::string fmt, BOOST_PP_REPEAT_Z(z)(n, BOOST_PARAMETER, T)) \
    { \
         BOOST_LOG_STREAM_WITH_PARAMS(boost::log::trivial::logger::get(), \
            (boost::log::keywords::severity = level)) << info << boost::format(fmt) BOOST_PP_REPEAT_Z(z)(n, BOOST_ARGUMENT, T); \
    }
#endif // !REPEAT_BLOG

template<typename T>
inline void blog(boost::log::trivial::severity_level level, std::string info, T value)
{
    blog(level, info, "%1%", value);
}

inline void blog(boost::log::trivial::severity_level level, std::string info)
{
    blog(level, info, "");
}

BOOST_PP_REPEAT_FROM_TO(1, 10, REPEAT_BLOG, _);

#ifndef LOG
#  define LOG(lvl_, ...) blog(boost::log::trivial::##lvl_, (boost::format("[%-15s:% 4d] ") % std::string(__FUNCTION__).substr(0, 15) % __LINE__).str(), ##__VA_ARGS__)
#endif // !LOG

#ifndef LOG_IF
#  define LOG_IF(c, lvl_, ...) if (c) { LOG(lvl_, ##__VA_ARGS__); }
#endif // !LOG_IF


