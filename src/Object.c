#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>

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

static void * Object_clone (const void * _self)
{
    return new(Object);
}

static int Object_compare (const void * _self, const void * _b)
{    
	const struct Object * self = _self;
    const struct Object * b = _b;
    if (self == b)
        return COMPARE_EQUAL;
    else 
    	return COMPARE_DIFFERENT;
}

static const struct Class _Object = {
	sizeof(struct Object),
	Object_ctor, Object_dtor,
	Object_clone, Object_compare
};

const void * Object = & _Object;


void * retain (void * _object) {
	struct Object * self = _object;
	self -> ref_count++;
	return self;
}

void release (void * _object) {
	struct Object * self = _object;
	
	self -> ref_count--;
	if (self -> ref_count < 0)
		Throw(OBJECT_RELEASE_DELETED_OBJECT);
	if (self -> ref_count == 0)
		delete(_object);
}

void * class(const void * _object) {
	const struct Object * self = _object;	
	return self -> class;
}
