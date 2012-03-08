#ifndef	_CLASS_H_
#define	_CLASS_H_

#include <stddef.h>
/**
  @file Class.h
  @brief Offer methods to create/delete/compare objects

  @author Bertrand Cachet
*/

enum OBJECT_COMPARISON {
  COMPARE_EQUAL,
  COMPARE_DIFFERENT
};

void * new (const void * class, ...);
void delete (void * item);

void * clone(const void * self);
int compare(const void * self, const void * other);

size_t sizeOf (const void * self);

#endif
