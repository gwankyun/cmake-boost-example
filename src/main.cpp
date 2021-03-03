#include <iostream>
#include <string>
#include <vector>
#include <type_traits>
#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/crc.hpp>
#include <boost/outcome.hpp>
#include <boost/utility/result_of.hpp>
#include "asio/log.hpp"
#include "hex.hpp"
#include <boost/type_index.hpp>
#include <boost/core/ref.hpp>
#include <boost/type_traits.hpp>

namespace outcome = BOOST_OUTCOME_V2_NAMESPACE;

inline uint32_t crc32(const void* data, std::size_t length)
{
    boost::crc_32_type crc;
    crc.process_bytes(data, length);
    return crc.checksum();
}

enum Div
{
    Success = 0,
    Zero
};

namespace test
{
    inline outcome::result<int> div(int a, int b)
    {
        if (b == 0)
        {
            return boost::system::errc::invalid_argument;
        }
        return outcome::success<int>(a / b);
    }
}

//struct void_t
//{
//    typedef void type;
//};

namespace type_index
{
    void f()
    {
    }

    template<typename T>
    void f_lref(T& param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void f_lcref(const T& param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void f_ptr(T* param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void f_cptr(const T* param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void f_value(T param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void f_uref(T&& param)
    {
        LOG(debug, boost::typeindex::type_id_with_cvr<decltype(param)>().pretty_name());
    }

    template<typename T>
    void update(T n)
    {
        n.get() = 1;
    }

    void test()
    {
        int x = 27;
        const int cx = x;
        const int& rx = x;
        int a[] = { 1, 2, 3 };
        f_lref(x);
        f_lref(cx);
        f_lref(rx);
        //f_lref(27);
        f_value(f);
        f_lcref(x);
        f_lcref(cx);
        f_lcref(27);
        f_lcref(rx);
        f_ptr(&x);
        f_ptr(&cx);
        f_cptr(&x);
        f_cptr(&cx);
        f_uref(x);
        f_uref(cx);
        f_uref(rx);
        f_uref(27);
        LOG(info, "value");
        LOG(info, "array");
        f_value(x);
        f_value(cx);
        f_value(27);
        f_value(rx);
        f_lref(a); // int (&)[3]
        f_value(a); // int *
        f_uref(a); // int (&)[3]
        LOG(info, "function");
        f_value(f);
        f_lref(f);
        f_uref(f);

        int n = 0;
        update(boost::ref(n));
        LOG(info, "n: %1%", n);
    }
}

struct void_t
{
    typedef void type;
};

template<typename F>
void funcInfo(F f)
{
    LOG(info, boost::typeindex::type_id_with_cvr<F>().pretty_name());
    LOG(info, boost::typeindex::type_id_with_cvr<typename boost::result_of<F()>::type >().pretty_name());
    LOG(info, std::is_same_v<typename boost::result_of<F()>::type, void_t::type>);
}

//template<typename F, typename T>
//typename boost::enable_if_<
//    !boost::is_same<typename boost::result_of<F(T)>::type, typename void_t::type>::value,
//    typename boost::result_of<F(T)>::type
//>::type apply(F fn, T value)
//{
//    return f(value);
//}

template<typename F, typename T>
typename boost::conditional<
    boost::is_same<typename boost::result_of<F(T)>::type, typename void_t::type>::value,
    typename void_t::type,
    typename boost::result_of<F(T)>::type
>::type apply(F fn, T value)
{
    return f(value);
}

//template<typename F, typename T>
//typename boost::enable_if_<
//    boost::is_same<typename boost::result_of<F(T)>::type, typename void_t::type>::value,
//    typename void_t::type
//>::type apply(F fn, T value)
//{
//    f(value);
//}

//template<typename F, typename T>
//void apply(F fn, T value)
//{
//    f(value);
//}

//template<typename F, typename T>
//typename boost::conditional<
//    boost::is_same<typename boost::result_of<F(T)>::type, typename void_t::type>::value,
//    typename void_t::type,
//    typename boost::result_of<F(T)>::type
//>::type apply(F fn, T value)
//{
//    f(value);
//}

int f(int n)
{
    return n + 1;
}

void g(int n)
{
    LOG(info, "n + 1: %1%", n + 1);
}

int main()
{
    BOOST_LOG_TRIVIAL(info) << boost::filesystem::current_path();
    std::string str("hello world, Boost.");
    std::vector<std::string> result;
    boost::split(result, str, boost::is_any_of(" ,."), boost::token_compress_on);
    for (auto&& i : result)
    {
        BOOST_LOG_TRIVIAL(info) << i << " " << boost::to_upper_copy(i) << " " << boost::to_lower_copy(i);
    }

    LOG(info, "hex: %1%", hex(str.begin(), str.end()));
    LOG(info, "hex: %1%", hex_n(str.begin(), str.size()));

    auto crc = crc32(str.c_str(), str.size());
    LOG(info, "crc: %1%", crc);

    LOG(info, "log: %1%", 1);
    LOG(info, "log: %1% %2%", 1, 2);
    LOG(info, "log: %1% %2% %3%", 1, 2, 3);
    LOG(info, "log: %1% %2% %3% %4%", 1, 2, 3, 4);
    LOG(info, "log: %1% %2% %3% %4% %5%", 1, 2, 3, 4, 5);
    LOG(info, "log: %1% %2% %3% %4% %5% %6%", 1, 2, 3, 4, 5, 6);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7%", 1, 2, 3, 4, 5, 6, 7);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7% %8%", 1, 2, 3, 4, 5, 6, 7, 8);
    LOG(info, "log: %1% %2% %3% %4% %5% %6% %7% %8% %9%", 1, 2, 3, 4, 5, 6, 7, 8, 9);
    LOG(info, 2);
    LOG(info);
    LOG_IF(test::div(2, 1), info, "%1% div %2% = %3%", 2, 1, test::div(2, 1).value());
    LOG_IF(test::div(2, 0), info, "%1% div %2% = %3%", 2, 0, test::div(2, 0).value());

    type_index::test();

    std::vector<int> v1(10, 20);
    LOG(info, "v1 %1%", v1.size());

    std::vector<int> v2({ 10, 20 });
    LOG(info, "v2 %1%", v2.size());

    funcInfo(type_index::test);

    //std::cout << apply(f, 0) << std::endl;
    //apply(g, 0);

    //LOG(info, std::apply(f, std::make_tuple(0)));
    //std::apply(g, std::make_tuple(0));

    return 0;
}