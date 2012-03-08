#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Object.h"

#include "CException.h"

static struct Class * Object_ctor (struct Class * self, va_list * app)
{
  ((struct Object *)self) -> ref_count = 1;
  return self;
}

static struct Class * Object_dtor (struct Class * self)
{
  ((struct Object *)self) -> ref_count = 0;
  return self;
}

static struct Class * Object_clone (const struct Class * _self)
{
    return new(ClassObject);
}

static int Object_compare (const struct Class * self, const struct Class * b)
{
  if (self == b)
    return COMPARE_EQUAL;
  else
    return COMPARE_DIFFERENT;
}

static const struct Class _Object = {
  sizeof(struct Object),
  Object_ctor, Object_dtor,
  Object_clone, Object_compare
};

const struct Class * ClassObject = & _Object;

void * retain (struct Object * self) {
#ifdef REFERENCE_COUNTING
  self -> ref_count++;
#endif
  return self;
}

void release (struct Object * self) {
#ifdef REFERENCE_COUNTING
  self -> ref_count--;
  if (self -> ref_count < 0)
    Throw(OBJECT_RELEASE_DELETED_OBJECT);
  if (self -> ref_count == 0)
    delete((struct Class *)self);
#endif
}

bool isOfClass(const struct Object * self, const struct Class * _class) {
  if (self == NULL)
    return false;
  return self -> class == _class;
}

