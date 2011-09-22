#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "Array.h"
#include "Array.r"

static void * Array_ctor (void * _self, va_list * app) {
  // Call Super constructor
  struct Array * self = ((struct Class *) Object) -> ctor(_self, app);
  // Set params
  const int size = va_arg(* app, int);
  self -> _size = size;
  self -> _objects = realloc(NULL, size*sizeof(void*));
  self -> _count = 0;
  self -> add = array_add;

  self -> remove = array_remove;
  self -> insert = array_insert;
  self -> get = array_get;
  self -> count = array_count;
  self -> size = array_size;
  self -> clear = array_clear;

  assert(self -> _objects);
  return self;
}

static void * Array_dtor (void * _self) {
  struct Array * self = _self;
  array_clear(self);
  free(self -> _objects);
  return self;
}

static int Array_compare(void * _self, void * _b) {
  struct Array * self = _self;
  struct Array * b = _b;
  if (self == b)
    return COMPARE_EQUAL;
  if (isOfClass(b, Array) == false || isOfClass(self, Array) == false)
    return COMPARE_DIFFERENT;
  if (self -> _count == b -> _count) {
    int i = 0;
    for (i = 0; i < self -> _count; i++) {
      if (compare(self -> _objects[i], b -> _objects [i]) == COMPARE_DIFFERENT)
        return COMPARE_DIFFERENT;
    }
    return COMPARE_EQUAL;
  }
  return COMPARE_DIFFERENT;
}

static void * Array_clone (const void * _self) {
  const struct Array * self = _self;
  void *_clone = new(Array, self -> _size);
  int i;
  for (i = 0; i < self -> _count; i++) {
    array_add(_clone, self -> _objects[i]);
  }
  return _clone;
}

static const struct Class _Array = {
  sizeof(struct Array),
  Array_ctor, Array_dtor,
  Array_clone, Array_compare, 
};

const void * Array = & _Array;

void array_reallocateMemory(void * _self) {
  struct Array * self = _self;
  int i = 0;
  self -> _size += ARRAY_REALLOCATION_SIZE;
  self -> _objects = realloc(self -> _objects, self -> _size*sizeof(void*));
  assert(self -> _objects);
}

unsigned int array_add(void * _self, void * element) {
  struct Array * self = _self;
  if(self -> _count >= self -> _size) {
    array_reallocateMemory(self);
  }
#ifdef REFERENCE_COUNTING
  self -> _objects[self -> _count] = retain(element);
#else
  self -> _objects[self -> _count] = element;
#endif
  self -> _count ++;
  return self -> _count - 1;
}

unsigned int array_insert(void * _self, void * element, unsigned int _index) {
  struct Array * self = _self;
  const int index = _index;
  assert(index <= self -> _count);

  if(self -> _count >= self -> _size) {
    array_reallocateMemory(_self);
  }
  int i = self -> _count - 1;
  while (i >= index) {
    self -> _objects[i + 1] = self -> _objects[i];
    i--;
  }
#ifdef REFERENCE_COUNTING
  self -> _objects[index] = retain(element);
#else
  self -> _objects[index] = element;
#endif
  self -> _count ++;
  return index;
}

void * array_get(void * _self, unsigned int index) {
  struct Array * self = _self;
  assert(index < self -> _count);
  return self -> _objects[index];
}

void * array_remove(void * _self, unsigned int index) {
  struct Array * self = _self;
  assert(index < self -> _count);
  void * element = *(self -> _objects + index);
  int i = index;
  for (i = index; i < self -> _count - 1; i++) {
    self -> _objects[i] = self -> _objects[i + 1];
  }
  self -> _count --;
#ifdef REFERENCE_COUNTING
  release(element);
#endif
  return element;
}

unsigned int array_count(void * _self) {
  struct Array * self = _self;
  return self -> _count;
}

unsigned int array_size(void * _self) {
  struct Array * self = _self;
  return self -> _size;
}

void array_clear(void * _self) {
  struct Array * self = _self;
  int i = 0;
  for (i = 0; i < self -> _count; i++) {
#ifdef REFERENCE_COUNTING
    release(*(self -> _objects + i));
#endif
  }
  self -> _count = 0;
}

