#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "Array.h"
#include "Array.r"
#include "Class.h"
#include "Class.r"

static void * Array_ctor (void * _self, va_list * app) {
  // Call Super constructor
  struct Array * self = ((struct Class *) Object) -> ctor(_self, app);
  // Set params
  const int size = va_arg(* app, int);
  self -> size = size;
  self -> objects = realloc(NULL, size*sizeof(void*));
  self -> count = 0;
  assert(self -> objects);
  return self;
}

static void * Array_dtor (void * _self) {
  struct Array * self = _self;
  array_clear(self);
  free(self -> objects);
  return self;
}

static int * Array_compare(void * _self, void * _b) {
  const struct Array * self = _self;
  const struct Array * b = _b;

  if (self == b)
    return COMPARE_EQUAL;
  if (! b || class(b) != Array)
    return COMPARE_DIFFERENT;
  if (self -> count == b -> count) {
    int i = 0;
    for (i = 0; i < self -> count; i++) {
      if (compare(self -> objects[i], b -> objects [i]) == COMPARE_DIFFERENT)
        return COMPARE_DIFFERENT;
    }
    return COMPARE_EQUAL;
  }
  return COMPARE_DIFFERENT;
}

static const struct Class _Array = {
  sizeof(struct Array),
  Array_ctor, Array_dtor,
  NULL, Array_compare
};

const void * Array = & _Array;

void array_reallocateMemory(void * _self) {
  struct Array * self = _self;
  int i = 0;
  self -> size += ARRAY_REALLOCATION_SIZE;
  self -> objects = realloc(self -> objects, self -> size*sizeof(void*));
  assert(self -> objects);
}

unsigned int array_add(void * _self, void * element) {
  struct Array * self = _self;
  if(self -> count >= self -> size) {
    array_reallocateMemory(self);
  }
  self -> objects[self -> count] = retain(element);
  self -> count ++;
  return self -> count - 1;
}

unsigned int array_insert(void * _self, void * element, unsigned int _index) {
  struct Array * self = _self;
  const int index = _index;
  assert(index <= self -> count);

  if(self -> count >= self -> size) {
    array_reallocateMemory(_self);
  }
  int i = self -> count - 1;
  while (i >= index) {
    self -> objects[i + 1] = self -> objects[i];
    i--;
  }
  self -> objects[index] = retain(element);
  self -> count ++;
  return index;
}

void * array_get(void * _self, unsigned int index) {
  struct Array * self = _self;
  assert(index < self -> count);
  return self -> objects[index];
}

void * array_remove(void * _self, unsigned int index) {
  struct Array * self = _self;
  assert(index < self -> count);
  void * element = *(self -> objects + index);
  int i = index;
  for (i = index; i < self -> count - 1; i++) {
    self -> objects[i] = self -> objects[i + 1];
  }
  self -> count --;
  release(element);
  return element;
}

const unsigned int array_count(void * _self) {
  struct Array * self = _self;
  return self -> count;
}

unsigned int array_size(void * _self) {
  struct Array * self = _self;
  return self -> size;
}

void array_clear(void * _self) {
  struct Array * self = _self;
  int i = 0;
  for (i = 0; i < self -> count; i++) {
    release(*(self -> objects + i));
  }
  self -> count = 0;
}

