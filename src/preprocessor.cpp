#include <boost/preprocessor.hpp>

#define TYPENAME(z, n, text) typename T##n

#define PARAM(z, n, text) const text##n& text##n##_

#define ARG(z, n, text) text##n##_

template<typename T, BOOST_PP_ENUM(2, TYPENAME, T)>
T* make_ptr(BOOST_PP_ENUM(2, PARAM, T))
{
    return new T(BOOST_PP_ENUM(2, ARG, T));
}

class Object
{
public:
	Object(int a, int b)
	{
	}

	~Object()
	{
	}

private:

};


int main()
{
	auto o = make_ptr<Object>(1, 2);
	delete o;
    return 0;
}