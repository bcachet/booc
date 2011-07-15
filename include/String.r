#ifndef	_STRING_R_
#define	_STRING_R_

#include "Object.r"

struct String {
	const struct Object _;
	char * text;
};

#endif