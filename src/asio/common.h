#pragma once
#include <boost/asio.hpp>
#include <boost/system/error_code.hpp>
#include <log.hpp>
#include "buffer.hpp"
#include "data.h"
#include "option.hpp"

namespace asio = boost::asio;
using error_code_t = boost::system::error_code;
using socket_t = asio::ip::tcp::socket;

template<>
inline std::string to_string(error_code_t error)
{
    return (boost::format("{ value: %1% message: %2% }") % error.value() % error.message()).str();
}

template<>
inline std::string to_string(asio::ip::tcp::endpoint remote_endpoint)
{
    return (boost::format("{ %1%:%2% }") % remote_endpoint.address().to_string() % remote_endpoint.port()).str();
}

inline void on_error(error_code_t error, const socket_t& socket)
{
    LOG_DBG(error, error);
    auto remote_endpoint = socket.remote_endpoint();
    LOG_DBG(error, remote_endpoint);
}

inline filesystem::path execution_path()
{
    char fileName[MAX_PATH] = { '\0' };
    GetModuleFileNameA(NULL, fileName, sizeof(fileName));
    filesystem::path path(fileName);
    return path.parent_path();
}
