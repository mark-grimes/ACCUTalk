/*
 * Helper struct that will give the Nth type in the list
 */
template<unsigned N,typename T,typename... Ts>
struct mytuple_typehelper
{
	typedef typename mytuple_typehelper<N-1,Ts...>::type type;
};
template<typename T,typename... Ts>
struct mytuple_typehelper<0,T,Ts...>
{
	typedef T type;
};

/*
 * Helper struct that will return the correct parameter
 *
 * Forward declared because the mytuple definition needs to use it, but
 * not defined because it needs to use the mytuple definition.
 */
template<unsigned N,typename T,typename... Ts>
struct mytuple_valuehelper;


template<typename T,typename... Ts>
struct mytuple
{
	template<unsigned N> using type=typename mytuple_typehelper<N,T,Ts...>::type;
	using head_type=T;
	using tail_type=mytuple<Ts...>;
	T head;
	mytuple<Ts...> tail;

	template<unsigned N>
	type<N>& method_get()
	{
		return mytuple_valuehelper<N,T,Ts...>::get_ref(*this);
	}

	/* For C++17 we can simplify considerably with "if constexpr" (static if) */
	// template<unsigned N>
	// auto& method_get()
	// {
	// 	if constexpr( N==0 ) return head;
	// 	else return tail.method_get<N-1>();
	// }
};
template<typename T>
struct mytuple<T>
{
	template<unsigned N> using type=typename mytuple_typehelper<N,T>::type;
	T head;

	template<unsigned N>
	type<N>& method_get()
	{
		return head;
	}
};



/*
 * Definition of the mytuple_valuehelper declared above
 */
template<unsigned N,typename T,typename... Ts>
struct mytuple_valuehelper
{
	static typename mytuple_typehelper<N,T,Ts...>::type& get_ref( mytuple<T,Ts...>& tuple )
	{
		return mytuple_valuehelper<N-1,Ts...>::get_ref( tuple.tail );
	}
};
template<typename T,typename... Ts>
struct mytuple_valuehelper<0,T,Ts...>
{
	static T& get_ref( mytuple<T,Ts...>& tuple )
	{
		return tuple.head;
	}
};


/*
 * As a slight aside, implement a version of std::is_same for fun
 */
template<typename T,typename U>
struct my_same
{
	static constexpr bool value=false;
};
template<typename T>
struct my_same<T,T>
{
	static constexpr bool value=true;
};
