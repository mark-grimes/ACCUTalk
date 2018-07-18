#pragma once

// In C++ 14, can have much more complex constexpr functions
constexpr unsigned long long fibonacci( unsigned N )
{
	if( N==0 ) return 0;
	else if( N==1 ) return 1;
	else return fibonacci(N-1)+fibonacci(N-2);
}
