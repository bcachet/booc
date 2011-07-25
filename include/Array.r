#ifndef	_ARRAY_R_
#define	_ARRAY_R_

#include "Object.r"

struct Array {
	const struct Object _;
	void ** objects;
	unsigned int count;
	void ** lastObject;
	unsigned int size;
};

#endif