#ifndef	_ARRAY_R_
#define	_ARRAY_R_

#include "Object.r"

struct Array {
  const struct Object _;
  void ** objects;
  unsigned int _count;
  unsigned int _size;

  
  unsigned int  (*add)(void * array, void * element);
  void *        (*remove)(void * array, unsigned int index);
  unsigned int  (*insert)(void * array, void * element, unsigned int index);
  void *        (*get)(void * array, unsigned int index);
  unsigned int  (*count)(void * array);
  unsigned int  (*size)(void * array);
  void          (*clear)(void * array);
};

#endif
