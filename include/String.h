#ifndef	_BC_STRING_H_
#define	_BC_STRING_H_

#include "Object.h"
#include "Class.h"

extern const struct Class * ClassString;

struct String {
  const struct Object obj;
  char * text;
};


char * string(const struct String * string);

#endif
