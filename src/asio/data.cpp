#ifdef BOOST_ALL_NO_LIB
#undef BOOST_ALL_NO_LIB
#endif
#include "data.h"
#include <sstream>
#include <string>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "buffer.hpp"
#include "../../include/log.hpp"

Data::Data()
    : uuid(boost::uuids::to_string(boost::uuids::random_generator()()))
{

}

Data::~Data()
{

}

void pack(const Data& data, std::string& buffer)
{
    std::stringstream obuffer;
    boost::archive::text_oarchive otext(obuffer);
    otext << data;
    buffer = obuffer.str();
}

bool unpack(const std::string& buffer, Data& data)
{
    try
    {
        std::stringstream ibuffer(buffer);
        boost::archive::text_iarchive itext(ibuffer);
        itext >> data;
    }
    catch (const std::exception& e)
    {
        LOG_DBG(error, e.what());
        return false;
    }
    return true;
}

void pack(const Data& data, Buffer& buffer)
{
    std::string obuffer;
    pack(data, obuffer);
    std::uint32_t len = static_cast<uint32_t>(obuffer.size());
    buffer.append(len);
    buffer.append(obuffer);
    assert(buffer.size() == len + sizeof(len));
}

DataState unpack(const Buffer& buffer, Data& data)
{
    if (buffer.offset() < sizeof(uint32_t))
    {
        return DataState::Part;
    }
    std::uint32_t len = *reinterpret_cast<uint32_t*>(buffer.data());
    if (len + sizeof(uint32_t) > buffer.offset())
    {
        return DataState::Part;
    }
    std::vector<char> str(buffer.offset() - sizeof(uint32_t) + 1, '\0');
    std::copy_n(buffer.data() + sizeof(uint32_t), len, reinterpret_cast<Buffer::value_type*>(str.data()));
    std::string s(str.data());
    if (!unpack(s, data))
    {
        return DataState::Error;
    }
    return DataState::Full;
}
