#ifndef	_CLASS_H_
#define	_CLASS_H_

#include <stdarg.h>
/**
  @file Class.h
  @brief Offer methods to create/delete/compare objects

  @author Bertrand Cachet
*/

enum OBJECT_COMPARISON {
  COMPARE_EQUAL,
  COMPARE_DIFFERENT
};

struct Class {
  size_t size;
  void * (* ctor) (void * self, va_list * app);
  void * (* dtor) (void * self);
  void * (* clone) (const void * self);
  int (* compare) (const void * self, const void * other);
};


struct Class * new (const struct Class * class, ...);
void delete (struct Class * item);

void * clone(const struct Class * self);
int compare(const struct Class * self, const struct Class * other);

size_t sizeOf (const struct Class * self);

#endif
