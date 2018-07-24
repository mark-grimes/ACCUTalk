# example07_struct_cpp11

Does the same as example06 except with a normal C struct. Used to show the difference in produced
assembly between using template meta programming and standard techniques.

With optimisation level 0 example06 produces much more assembly than this version, but on
optimisation level 1 both examples boil down to the "mov 0x64" simplest possible code.
