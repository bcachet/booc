#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "String.h"

static struct Class * String_ctor (struct Class * _self, va_list * app) {
  // Call Super constructor
  struct String * self = ((const struct Class *) ClassObject) -> ctor(_self, app);

  // Set params
  const char * text = va_arg(* app, const char *);
  self -> text = malloc(strlen(text) + 1);
  assert(self -> text);
  strcpy(self -> text, text);

  return self;
}

static struct Class * String_dtor (struct Class * _self)
{
  struct String * self = _self;
  free(self -> text), self -> text = 0;
  return self;
}

static struct Class * String_clone (const struct Class * _self)
{
  const struct String * self = _self;
  return new(ClassString, self -> text);
}

static int String_compare (const struct Class * _self, const struct Class * _b)
{
  const struct String * self = _self;
  const struct String * b = _b;

  if (self == b)
    return COMPARE_EQUAL;
  if (isOfClass(b, ClassString) == false || isOfClass(self, ClassString) == false)
    return COMPARE_DIFFERENT;
  return strcmp(self -> text, b -> text) == 0 ? COMPARE_EQUAL : COMPARE_DIFFERENT;
}

static const struct Class _String = {
  sizeof(struct String),
  String_ctor, String_dtor,
  String_clone, String_compare
};

const struct Class * ClassString = & _String;


char * string(const struct String * self) {
  return self -> text;
}

