#pragma once
#include <boost/log/trivial.hpp>
#include <boost/format.hpp>

#define BLOG(lvl_, fmt_) \
    BOOST_LOG_TRIVIAL(lvl_) << (boost::format("[%-10s:% 4d] ") % __func__ % __LINE__) << boost::format(fmt_)
