#pragma once
#include <boost/log/trivial.hpp>
#include <boost/format.hpp>
#include <string>
#include <fstream>

#ifndef LOG
#define LOG(lvl_, fmt_) \
    BOOST_LOG_TRIVIAL(lvl_) << (boost::format("[%-10s:% 4d] ") % std::string(__func__).substr(0, 10) % __LINE__) << boost::format(fmt_)
#endif // !LOG
