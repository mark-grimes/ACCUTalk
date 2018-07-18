#pragma once

template<unsigned N>
struct Fibonacci
{
	static const unsigned long long value=Fibonacci<N-1>::value+Fibonacci<N-2>::value;
};

template<>
struct Fibonacci<0>
{
	static const unsigned long long value=0;
};

template<>
struct Fibonacci<1>
{
	static const unsigned long long value=1;
};
