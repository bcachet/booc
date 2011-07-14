#include <assert.h>
#include <stdlib.h>

#include "Class.h"
#include "Class.r"

void * new (const void * _class, ...)
{	const struct Class * class = _class;
	void * p = calloc(1, class -> size);

	assert(p);
	* (const struct Class **) p = class;

	if (class -> ctor)
	{	va_list ap;

		va_start(ap, _class);
		p = class -> ctor(p, & ap);
		va_end(ap);
	}
	printf("Create object %d\n", p);
	return p;
}

void delete (void * self)
{	const struct Class ** cp = self;
	printf("Delete object %d\n", self);
	if (self && * cp && (* cp) -> dtor)
		self = (* cp) -> dtor(self);
	free(self);
}

size_t sizeOf (const void * self)
{	const struct Class * const * cp = self;

	assert(self && * cp);
	return (* cp) -> size;
}