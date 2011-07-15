#ifndef _OBJECT_H_
#define _OBJECT_H_

#define OBJECT_RELEASE_DELETED_OBJECT	0x010203

extern const void * Object;

void * retain (void * object);
void release (void * object);

void * class(const void * object);

#endif