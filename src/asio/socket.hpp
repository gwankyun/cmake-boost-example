#pragma once
#include <cstdint> // std::uint32_t
#include <cstring> // memset
#include <boost/asio/yield.hpp>
#include <boost/asio.hpp>

struct Header
{
    char sign[4]; // 4��@��ʾ���^
    std::uint16_t headerLength; // ���^�L
    std::uint16_t headerType; // ���^��ͣ�Ĭ�J0������չ����
    std::uint32_t headerChecksum; // ���^У��
    std::uint32_t bodyLength; // ���w�L
    std::uint16_t bodyMajorType; // ���w����ͣ���bodyMinorType��Ϙ��R���w�Ĕ������
    std::uint16_t bodyMinorType; // ���w�����
    std::uint32_t bodyChecksum; // ���^У��
};

inline void initialize(Header& header)
{
    memset(header.sign, '@', sizeof(header.sign));
    header.headerLength = sizeof(header);
    header.headerType = 0;
    header.headerChecksum = 0;
    header.bodyLength = 0;
    header.bodyMajorType = 0;
    header.bodyMinorType = 0;
    header.bodyChecksum = 0;
}

inline boost::asio::BOOST_ASIO_CONST_BUFFER writeBuffer(const void* data, std::size_t size_in_bytes, std::size_t offset)
{
    return boost::asio::buffer(
        (const char*)data + offset, size_in_bytes - offset);
}

inline boost::asio::BOOST_ASIO_MUTABLE_BUFFER readBuffer(void* data, std::size_t size_in_bytes, std::size_t offset)
{
    return boost::asio::buffer(
        (char*)data + offset, size_in_bytes - offset);
}

template<typename S, typename F>
inline void asyncWrite(S& socket, const void* data, std::size_t size_in_bytes, std::size_t offset, F fn)
{
    socket.async_write_some(
        writeBuffer(data, size_in_bytes, offset),
        fn);
}

template<typename S, typename F>
inline void asyncRead(S& socket, void* data, std::size_t size_in_bytes, std::size_t offset, F fn)
{
    socket.async_read_some(
        readBuffer(data, size_in_bytes, offset),
        fn);
}

template<typename S, typename E, typename F>
inline void asyncConnect(S& socket, E endpoint, F fn)
{
    socket.async_connect(endpoint, fn);
}

template<typename S, typename T, typename F>
inline void asyncWait(S& socket, T t, F& fn)
{
    //fn.isTimer.reset(new bool(true));
    fn.timer.reset(new boost::asio::steady_timer(socket.get_executor(), t));
    fn.timer->async_wait([fn, &socket](boost::system::error_code error)
        {
            LOG(debug, "");
            if (error)
            {
                if (error != boost::system::errc::operation_canceled)
                {
                    LOG(debug, "%1%", error.message());
                }
                return;
            }
            //LOG(debug, "isTimer: %1%", *(fn.isTimer));
            //if (*(fn.isTimer))
            {
                LOG(debug, "timeout!");
                socket.close();
                return;
            }
        });
}
