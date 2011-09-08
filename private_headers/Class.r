#ifndef	_CLASS_R_
#define	_CLASS_R_

#include <stdarg.h>

struct Class {
  size_t size;
  void * (* ctor) (void * self, va_list * app);
  void * (* dtor) (void * self);
  void * (* clone) (const void * self);
  int (* compare) (const void * self, const void * other);
};

#endif
