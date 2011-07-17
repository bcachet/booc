#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "Array.h"
#include "Array.r"
#include "Class.h"
#define PTR_SIZE sizeof(void*)
#include "Class.r"


static void * Array_ctor (void * _self, va_list * app) {	
	// Call Super constructor
	struct Array * self = ((struct Class *) Object) -> ctor(_self, app);
	
	// Set params
	const int size = va_arg(* app, int);
	self -> size = size;
	self -> objects = malloc(size*PTR_SIZE);
	self -> count = 0;
	assert(self -> objects);
	return self;
}

static void * Array_dtor (void * _self)
{	
	struct Array * self = _self;
	int i = 0;
	for (i = 0; i < self -> count; i++) {
		release(*(self -> objects + i*PTR_SIZE));
	}
	// free(self -> objects);
	return self;
}

static const struct Class _Array = {
	sizeof(struct Array),
	Array_ctor, Array_dtor,
	NULL, NULL
};

const void * Array = & _Array;

void array_reallocateMemory(void * _self) {
	struct Array * self = _self;
	self -> size += ARRAY_REALLOCATION_SIZE;
	self -> objects = realloc(self -> objects, self -> size*PTR_SIZE);
	assert(self -> objects);
}

unsigned int array_add(void * _self, void * element) {
	struct Array * self = _self;
	if(self -> count >= self -> size) {
		array_reallocateMemory(self);
	}
	assert(self -> objects);
	*(self -> objects + self -> count*PTR_SIZE) = retain(element);
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
		*(self -> objects + (i + 1)*PTR_SIZE) = *(self -> objects + i*PTR_SIZE);
		i--;
	}
	*(self -> objects + index*PTR_SIZE) = retain(element);
	self -> count ++;
	return index;
}

void * array_get(void * _self, unsigned int index) {
	struct Array * self = _self;
	assert(index < self -> count);
	return *(self -> objects + index*PTR_SIZE);
}

void * array_remove(void * _self, unsigned int index) {
	struct Array * self = _self;
	assert(index < self -> count);
	void * element = *(self -> objects + index);
	int i = index;
	for (i = index; i < self -> count - 1; i++) {
		*(self -> objects + i*PTR_SIZE) = *(self -> objects + (i + 1)*PTR_SIZE);
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
