#include <boost/test/unit_test.hpp>
#include "data.hpp"

BOOST_AUTO_TEST_CASE(asio)
{
    Data data;
    data.message = "data";

    Buffer buffer;
    pack(data, buffer);
    buffer.offset() = buffer.size();

    Data result;
    unpack(buffer, result);
    BOOST_CHECK(data.message == result.message);
}
