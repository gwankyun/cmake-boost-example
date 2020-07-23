#pragma once
#include <cassert>
#include <sstream>
#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "buffer.hpp"
#include "log.hpp"

struct Data
{
    std::string message;
};

namespace boost
{
    namespace serialization
    {
        template<class Archive>
        void serialize(Archive& ar, Data& data, const unsigned int version)
        {
            (void)version;
            ar& data.message;
        }
    }
}

inline void pack(const Data& data, std::string& buffer)
{
    std::stringstream obuffer;
    boost::archive::text_oarchive otext(obuffer);
    otext << data;
    buffer = obuffer.str();
}

inline void unpack(const std::string& buffer, Data& data)
{
    std::stringstream ibuffer(buffer);
    boost::archive::text_iarchive itext(ibuffer);
    itext >> data;
}

inline void pack(const Data& data, Buffer& buffer)
{
    std::string obuffer;
    pack(data, obuffer);
    std::uint32_t len = static_cast<uint32_t>(obuffer.size());
    buffer.append(len);
    buffer.append(obuffer);
    assert(buffer.size() == len + sizeof(len));
}

inline bool unpack(const Buffer& buffer, Data& data)
{
    if (buffer.offset() < sizeof(uint32_t))
    {
        return false;
    }
    std::uint32_t len = *reinterpret_cast<uint32_t*>(buffer.data());
    if (len + sizeof(uint32_t) > buffer.offset())
    {
        return false;
    }
    std::vector<char> str(buffer.offset() - sizeof(uint32_t) + 1, '\0');
    std::copy_n(buffer.data() + sizeof(uint32_t), len, reinterpret_cast<Buffer::value_type*>(str.data()));
    std::string s(str.data());
    unpack(s, data);
    return true;
}
