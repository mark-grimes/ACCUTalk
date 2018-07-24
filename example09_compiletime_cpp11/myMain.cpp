#include "NDimensionalBinner.h"

struct MyData
{
	int someData=0;
};

unsigned long long myMain()
{
	implbasic::impl::NDimensionalBinner<MyData,true,double,double> binner( 10, -0.5, 9.5, 5, -2, 2 );
	++binner.get(0,0).someData;
	++binner.get(0,-0.1).someData;
	++binner.get(0,0.1).someData;
	++binner.get(0,3).someData;
	return binner.get(0,0).someData;
}
