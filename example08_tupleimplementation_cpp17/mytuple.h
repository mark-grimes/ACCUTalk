#pragma once

template<typename T,typename... Ts>
struct mytuple
{
	T head;
	mytuple<Ts...> tail;

	template<unsigned N>
	auto& method_get()
	{
		if constexpr( N==0 ) return head;
		else return tail.template method_get<N-1>();
	}
};

/* Still need the base case, only because when `Ts` is empty can't have `mytuple<> tail;` */
template<typename T>
struct mytuple<T>
{
	T head;

	/* For C++17 we can simplify considerably with "if constexpr" (static if) */
	template<unsigned N>
	auto& method_get()
	{
		static_assert( N==0 );
		return head;
	}
};
