#pragma once
#include "buffer.hpp"

struct Data
{
    Data();
    ~Data();
    std::string message;
    std::string uuid;
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
            ar& data.uuid;
        }
    }
}

void pack(const Data& data, Buffer& buffer);

bool unpack(const Buffer& buffer, Data& data);

void pack(const Data& data, std::string& buffer);

void unpack(const std::string& buffer, Data& data);
