#ifndef	_ARRAY_R_
#define	_ARRAY_R_

#include "Object.r"

struct Array {
	const struct Object _;
	void ** elements;
	unsigned int count;
	unsigned int size;
};

#endif