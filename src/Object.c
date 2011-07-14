#include <assert.h>
#include <stdlib.h>

#include "Object.h"
#include "Object.r"
#include "Class.h"
#include "Class.r"

#include "CException.h"

static void * Object_ctor (void * _self, va_list * app)
{	
	struct Object * self = _self;
	self -> ref_count = 1;
	return self;
}

static void * Object_dtor (void * _self)
{	
	struct Object * self = _self;
	self -> ref_count = 0;
	return self;
}

static const struct Class _Object = {
	sizeof(struct Object),
	Object_ctor, Object_dtor
};

const void * Object = & _Object;


void * retain (void * _object) {
	struct Object * self = _object;
	self -> ref_count++;

}

void release (void * _object) {
	struct Object * self = _object;
	if (self -> ref_count <= 0)
		Throw(OBJECT_RELEASE_DELETED_OBJECT);
	self -> ref_count--;
	if (self -> ref_count == 0)
		delete(_object);
}