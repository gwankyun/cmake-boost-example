#define BOOST_TEST_MODULE header-only multiunit test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test1)
{
    int i = 1;
    BOOST_CHECK(i * i == 1);
}