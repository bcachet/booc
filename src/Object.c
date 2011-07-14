#include <assert.h>
#include <stdlib.h>

#include "Object.h"
#include "Object.r"
#include "Class.h"
#include "Class.r"

static void * Object_ctor (void * _self, va_list * app)
{	
	struct Object * self = _self;
	self -> ref_counting = 1;
	return self;
}

static void * Object_dtor (void * _self)
{	
	struct Object * self = _self;
	self -> ref_counting = 0;
	return self;
}

static const struct Class _Object = {
	sizeof(struct Object),
	Object_ctor, Object_dtor
};

const void * Object = & _Object;


void * retain (void * _object) {
	struct Object * self = _object;
	self -> ref_counting++;

}

void release (void * _object) {
	struct Object * self = _object;
	self -> ref_counting--;
	if (self -> ref_counting == 0)
		delete(_object);
}