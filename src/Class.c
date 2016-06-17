#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Class.h"

void* new (const Class* class, ...)
{
  void * p = calloc(1, class -> size);

  assert(p);
  * (const struct Class **) p = class;

  if (class -> ctor)
  {
    va_list ap;
    va_start(ap, class);
    p = class -> ctor(p, & ap);
    va_end(ap);
  }
  return p;
}

void delete(Obj* self)
{
  if(self && self->class && self->class->dtor)
  {
    free(self->class->dtor(self));
  }
}

Obj* clone(const Obj* self) {
  if(self && self->class && self->class->clone)
  {
    return self->class->clone(self);
  }
  return (Obj*)0;
}

int compare(const void * self, const void * other) {
  const struct Class * const * cp = self;
  assert(self && (*cp) && ((* cp) -> compare));
  return (* cp) -> compare(self, other);
}

size_t sizeOf (const void * self)
{
  const struct Class * const * cp = self;

  assert(self && * cp);
  return (* cp) -> size;
}

