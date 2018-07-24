#include "mytuple.h"
#include <catch.hpp>

SCENARIO( "Tests for the live coding at the ACCU talk" )
{
	mytuple<float,char,int> instance;
	instance.method_get<0>()=2.3;
	instance.method_get<1>()='F';
	instance.method_get<2>()=87;
	CHECK( instance.method_get<0>()==Approx(2.3) );
	CHECK( instance.method_get<1>()=='F' );
	CHECK( instance.method_get<2>()==87 );

	/* This should fail to compile because there aren't enough template parameters */
	// instance.method_get<3>()=87;
}
