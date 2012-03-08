#ifndef _OBJECT_H_
#define _OBJECT_H_

#define OBJECT_RELEASE_DELETED_OBJECT	0x010203

#include <stdbool.h>

#include "Class.h"

/**
  @file Object.h
  @brief Object offer methods to handle ref counting

  @author Bertrand Cachet
*/

struct Object {
  const struct Class * class;
  int ref_count;
};

extern const struct Class * ClassObject;


void * retain (struct Object * object);
void release (struct Object * object);

bool isOfClass(const struct Object * object, const struct Class * class);

#endif
