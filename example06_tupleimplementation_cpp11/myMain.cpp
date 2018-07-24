#include "mytuple.h"

unsigned long long myMain()
{
	mytuple<float,char,int> foo;
	foo.method_get<0>()=2.3;
	foo.method_get<1>()='F';
	foo.method_get<2>()=100;
	return foo.method_get<2>();
}
