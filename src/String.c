#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "String.h"
#include "String.r"
#include "Class.h"
#include "Class.r"

static void * String_ctor (void * _self, va_list * app) {	
	// Call Super constructor
	struct String * self = ((const struct Class *) Object) -> ctor(_self, app);
	
	// Set params
	const char * text = va_arg(* app, const char *);
	self -> text = malloc(strlen(text) + 1);
	assert(self -> text);
	strcpy(self -> text, text);

	return self;
}

static void * String_dtor (void * _self)
{	struct String * self = _self;

	free(self -> text), self -> text = 0;
	return self;
}

static void * String_clone (const void * _self)
{    
	const struct String * self = _self;
    return new(String, self -> text);
}

static int String_compare (const void * _self, const void * _b)
{    
	const struct String * self = _self;
    const struct String * b = _b;

    if (self == b)
        return COMPARE_EQUAL;
    if (! b || class(b) != String)
        return COMPARE_DIFFERENT;
    return strcmp(self -> text, b -> text) == 0 ? COMPARE_EQUAL : COMPARE_DIFFERENT;
}

static const struct Class _String = {
	sizeof(struct String),
	String_ctor, String_dtor,
	String_clone, String_compare
};

const void * String = & _String;


char * string(void * _self) {
	const struct String * self = _self;
	return self -> text;
}