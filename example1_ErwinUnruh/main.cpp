// Erwin Unruh, untitled program,
// ANSI X3J16-94-0075/ISO WG21-462, 1994.

template <int i>
struct D
{
	D(void *);
	operator int();
};

template <int p, int i>
struct is_prime
{
	enum { prim = (p%i) && is_prime<(i>2?p:0), i>::prim };
};

template <int i>
struct Prime_print
{
	Prime_print<i-1>    a;
	enum { prim = is_prime<i,i-1>::prim };
	void f() { D<i> d = prim; }
};

struct is_prime<0,0> { enum { prim = 1 }; };
struct is_prime<0,1> { enum { prim = 1 }; };
struct Prime_print<2>
{
	enum { prim = 1 };
	void f() { D<2> d = prim; }
};

void foo()
{
	Prime_print<10> a;
}
