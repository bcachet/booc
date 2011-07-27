#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include "Complex.h"
#include "Complex.r"
#include "Object.h"
#include "Object.r"
#include "Class.h"
#include "Class.r"


static void * Complex_ctor (void * _self, va_list * app) {
  // Call Super constructor
  struct Complex * self = ((const struct Class *) Object) -> ctor(_self, app);

  // Set params
  const double real = va_arg(* app, double);
  const double img = va_arg(* app, double);
  self -> real = real;
  self -> imaginary = img;
  return self;
}

static void * Complex_dtor (void * _self)
{
  struct Complex * self = _self;
  return self;
}

static const struct Class _Complex_ = {
  sizeof(struct Complex),
  Complex_ctor, Complex_dtor,
  NULL, NULL
};

const void * Complex = & _Complex_;

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
  return atan(self -> imaginary/self -> real);
}

