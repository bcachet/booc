#ifndef	_CLASS_H_
#define	_CLASS_H_

#include <stddef.h>

enum OBJECT_COMPARISON {
  COMPARE_EQUAL,
  COMPARE_DIFFERENT
};

void delete (void * item);
typedef struct Class Class;

struct Class {
  size_t size;
  void *(* ctor   ) (const Class* self, va_list * app);
  void *(* dtor   ) (void* self);
  void *(* clone  ) (const void* self);
  int   (* compare) (const void* self, const void* other);
};

void* new (const Class* class, ...);
void delete (void* item);

void * clone(const void * self);
int compare(const void * self, const void * other);

size_t sizeOf (const void * self);

#endif
