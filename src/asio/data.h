#pragma once
#include "buffer.hpp"

struct Data
{
    Data();
    ~Data();
    std::string message;
    std::string uuid;
};

enum struct DataState
{
    Full = 1,
    Part,
    Error
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

DataState unpack(const Buffer& buffer, Data& data);

void pack(const Data& data, std::string& buffer);

bool unpack(const std::string& buffer, Data& data);
