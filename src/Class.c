#include <assert.h>
#include <stdlib.h>

#include "Class.h"

struct Class * new (const struct Class * _class, ...)
{
  const struct Class * class = _class;
  void * p = calloc(1, class -> size);

  assert(p);
  * (const struct Class **) p = class;

  if (class -> ctor)
  {
    va_list ap;
    va_start(ap, _class);
    p = class -> ctor(p, & ap);
    va_end(ap);
  }
  return p;
}

void delete (struct Class * self)
{
  const struct Class ** cp = self;
  if (self && * cp && (* cp) -> dtor)
    self = (* cp) -> dtor(self);
  free(self);
  self = 0;
}

void * clone(const struct Class * self) {
  const struct Class * const * cp = self;
  assert(self && (*cp) && ((* cp) -> clone));
  return (* cp) -> clone(self);
}

int compare(const struct Class * self, const struct Class * other) {
  const struct Class * const * cp = self;
  assert(self && (*cp) && ((* cp) -> compare));
  return (* cp) -> compare(self, other);
}

size_t sizeOf (const struct Class * self)
{
  const struct Class * const * cp = self;

  assert(self && * cp);
  return (* cp) -> size;
}

