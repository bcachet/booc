#ifndef	_COMPLEX_R_
#define	_COMPLEX_R_

#include "Object.r"

struct Complex {
	const struct Object _;
	double real;
	double imaginary;
};

#endif
