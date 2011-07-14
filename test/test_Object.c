#include "unity.h"

#include "Object.h"
#include "Class.h"

struct Object *a;
struct Object *b;

void setUp(void)
{
	a = new(Object);
	b = new(Object);
}
 
void tearDown(void)
{
	release(a);
	release(b);
}

void test_Differ(void)
{
	
   
}