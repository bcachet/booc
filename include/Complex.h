#ifndef	_COMPLEX_H_
#define	_COMPLEX_H_

#include "Object.h"

extern const void * Complex;

double real(void * complex);
double imaginary(void * complex);
double absolute(void * complex);
double arg(void * complex);

#endif
