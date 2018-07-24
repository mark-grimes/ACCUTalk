# example08_tupleimplementation_cpp17

A version of mytuple from example06 using some C++17 features. The code is functionally the same but
the `mytuple.h` file is considerably simplified.

The features used are:
* Return type deduction using `auto` (this is actually C++14, but I thought it was C++17 when I
started writing this). This allows us to get rid of the `mytuple_typehelper` struct.
* Static if statements (`if constexpr(...)`). This simplifies things hugely by getting rid of the
`mytuple_valuehelper` struct which is really quite arcane. Maybe it's possible to simplify
`mytuple_valuehelper` in C++11 but I couldn't figure out how.

## Nota Bene

This doesn't actually compile with the compiler in the docker container (g++ 6.4.0) because it
complains about the `if constexpr(...)` statement. I've tested with LLVM 9.1.0 and it works fine
though.

Since it doesn't work the Makefile skips compilation if the compiler version is the one in the
docker container.
