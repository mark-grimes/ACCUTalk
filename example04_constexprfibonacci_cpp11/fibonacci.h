#pragma once

// In C++ 11, can only have a return statement, so still pretty limited
constexpr unsigned long long fibonacci( unsigned N )
{
	return N==0 ? 0 : N==1 ? 1 : fibonacci(N-1)+fibonacci(N-2);
}
