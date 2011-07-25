#include <math.h>

#include "Complex.h"
#include "Complex.r"

double real(void * _self) {
	struct Complex * self = _self;
	return self -> real;
}

double imaginary(void * _self) {
	struct Complex * self = _self;
	return self -> imaginary;
}

double absolute(void * _self) {
	struct Complex * self = _self;
	return sqrt(self -> real*self -> real + self->imaginary*self->imaginary);
}

double arg(void * _self) {
	struct Complex * self = _self;
	return arctan(self -> imaginary/self -> real);
}