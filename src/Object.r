#ifndef _OBJECT_R_
#define _OBJECT_R_

struct Object {
	const void * class;
	int ref_counting;
};

#endif