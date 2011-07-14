#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "String.h"
#include "String.r"
#include "Class.h"
#include "Class.r"

static void * String_ctor (void * _self, va_list * app)
{	struct String * self = ((const struct Class *) Object) -> ctor(_self, app);
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

static const struct Class _String = {
	sizeof(struct String),
	String_ctor, String_dtor
};

const void * String = & _String;
