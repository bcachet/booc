#ifndef _OBJECT_R_
#define _OBJECT_R_

#include "Class.r"

struct Object {
  const void * class;
  int ref_count;
};

#endif
