# example4

Use C++11 constexpr to evaluate the values at compile time.

Even when the compiler has all the information to deduce the values at compile time, sometimes you
have to force it to do so. This can be done either by assigning to a constexpr or increasing the
optimisation level.

A good talk on compiler optimisations is Jason Turner's at CppCon 16, [Rich Code for Tiny Computers:
A Simple Commodore 64 Game in C++17](https://www.youtube.com/watch?v=zBkNBP00wJE).
