#pragma once
#include "buffer.hpp"

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

void pack(const Data& data, Buffer& buffer);

bool unpack(const Buffer& buffer, Data& data);
