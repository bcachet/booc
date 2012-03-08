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


extern struct Object;

void * retain (void * object);
void release (void * object);

bool isOfClass(const void * object, const void * class);

#endif
