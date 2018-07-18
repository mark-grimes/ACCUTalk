#include "mytuple.h"
#include <catch.hpp>

SCENARIO( "Tests for the mytyple_typehelper struct" )
{
	CHECK( std::is_same<mytuple_typehelper<0,float,char,int>::type,float>::value );
	CHECK( std::is_same<mytuple_typehelper<1,float,char,int>::type,char>::value );
	CHECK( std::is_same<mytuple_typehelper<2,float,char,int>::type,int>::value );
	/*
	 * This next line should not compile because there are not enough type parameters
	 */
	// CHECK( std::is_same<mytuple_typehelper<3,float,char,int>::type,float>::value );
}

SCENARIO( "Tests for the live coding at the ACCU talk" )
{
	mytuple<float,char,int> instance;
	CHECK( std::is_same<mytuple<float,char,int>::type<0>,float>::value );
	CHECK( std::is_same<mytuple<float,char,int>::type<1>,char>::value );
	CHECK( std::is_same<mytuple<float,char,int>::type<2>,int>::value );
	/* This line should not compile */
	// CHECK( std::is_same<mytuple<float,char,int>::type<3>,char>::value );

	CHECK( std::is_same<mytuple<float>::type<0>,float>::value );

	/* Show that this is all calculated at compile time with C++11 static_assert */
	static_assert( std::is_same<mytuple<float,char,int>::type<0>,float>::value, "types are not equal" );

	instance.method_get<0>()=2.3;
	instance.method_get<1>()='F';
	instance.method_get<2>()=87;
	CHECK( instance.method_get<0>()==Approx(2.3) );
	CHECK( instance.method_get<1>()=='F' );
	CHECK( instance.method_get<2>()==87 );

	/* This should fail to compile because there aren't enough template parameters */
	// instance.method_get<3>()=87;
}

/*
 * I might not get around to this, but show a simple re-implemnation of std::is_same
 */
SCENARIO( "Tests for the my_same re-implementation of std::is_same" )
{
	CHECK( my_same<float,float>::value );
	CHECK( my_same<char,char>::value );
	CHECK( my_same<char*,char*>::value );
	CHECK_FALSE( my_same<float,char>::value );
	CHECK_FALSE( my_same<char,unsigned>::value );
	CHECK_FALSE( my_same<char*,char>::value );
}
