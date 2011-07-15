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
	self -> elements = malloc(size*sizeof(void*));
	self -> count = 0;
	assert(self -> elements);
	return self;
}

static void * Array_dtor (void * _self)
{	
	struct Array * self = _self;
	int i = 0;
	for (i = 0; i < self -> count; i++) {
		release(*(self -> elements + i));
	}
	free(self -> elements);
	self -> elements = 0;
	return self;
}

static const struct Class _Array = {
	sizeof(struct Array),
	Array_ctor, Array_dtor,
	NULL, NULL
};

const void * Array = & _Array;

unsigned int array_add(void * array, void * element) {
	struct Array * self = array;
	if(self -> count >= self -> size) {
		self -> size += ARRAY_REALLOCATION_SIZE;
		self -> elements = realloc(self -> elements, self -> size);
	}
	assert(self -> elements);
	*(self -> elements + self -> count) = element;
	retain(element);
	self -> count ++;
	return self -> count - 1;
}

void * array_remove(void * array, unsigned int index) {
	struct Array * self = array;
	assert(index < self -> count);
	void * element = *(self -> elements + index);
	int i = index;
	for (i = index; i < self -> count - 1; i++) {
		*(self -> elements + i) = *(self -> elements + i + 1);
	}
	self -> count --;
	release(element);
	return element;
}

unsigned int array_count(void * array) {
	struct Array * self = array;
	return self -> count;
}

unsigned int array_size(void * array) {
	struct Array * self = array;
	return self -> size;
}