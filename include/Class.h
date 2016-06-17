#ifndef	_CLASS_H_
#define	_CLASS_H_

#include <stddef.h>

enum OBJECT_COMPARISON {
  COMPARE_EQUAL,
  COMPARE_DIFFERENT
};


typedef struct Class Class;
typedef struct Obj Obj;


struct Class {
  size_t size;
  void *(* ctor   ) (const Class* self, va_list * app);
  void *(* dtor   ) (Obj* self);
  void *(* clone  ) (const Obj* self);
  int   (* compare) (const void* self, const void* other);
};

struct Obj { // Object is already taken for now
	Class* class;
	void*  object;
};

void* new (const Class* class, ...);
void  delete(Obj* item);
Obj*  clone(const Obj* self);
int   compare(const void * self, const void * other);

size_t sizeOf (const void * self);

#endif
