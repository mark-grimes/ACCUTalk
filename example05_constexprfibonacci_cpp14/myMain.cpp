#include "fibonacci.h"

unsigned long long myMain()
{
	return fibonacci( 48 );
}

/*
 * Need to assign to a constexpr to force the evaluation at compile time
 */
// unsigned long long myMain()
// {
// 	constexpr unsigned long long value=fibonacci( 48 );
// 	return value;
// }
