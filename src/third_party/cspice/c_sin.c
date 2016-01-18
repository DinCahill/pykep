#include "f2c.h"

#ifdef KR_headers
extern double sin(), cos(), sinh(), cosh();

VOID c_sin(r, z) complex *r, *z;
#else
#undef abs
#ifdef _WIN32
#define _COMPLEX_DEFINED
#endif
#include "math.h"

void c_sin(complex *r, complex *z)
#endif
{
	double zr = z->r;
	r->r = sin(zr) * cosh(z->i);
	r->i = cos(zr) * sinh(z->i);
	}
