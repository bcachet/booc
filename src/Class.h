#ifndef	_CLASS_H_
#define	_CLASS_H_

#include <stddef.h>

void * new (const void * class, ...);
void delete (void * item);

size_t sizeOf (const void * self);

#endif
