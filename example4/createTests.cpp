/*
 * Simple piece of code to create the test C++ code for a Fibonacci sequence.
 * The code is run and then the output copy-pasted into a test case.
 */

#include <iostream>
#include <limits>

int main()
{
	using MyInt=unsigned long long;
	MyInt prev1=0;
	MyInt prev2=1;
	for( size_t index=2; index<501; ++index )
	{
		if( prev2>std::numeric_limits<MyInt>::max()/2 )
		{
			std::cout << "Overflow expected at next iteration" << std::endl;
			break;
		}
		const MyInt total=prev1+prev2;
		std::cout << "SCENARIO( \"Test with " << index << "\" ) { unsigned long long result=Fibonacci<"
				<< index << ">::value; CHECK( result==" << total << "u ); }\n";
		prev1=prev2;
		prev2=total;
	}

	return 0;
}
