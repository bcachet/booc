#include "unity.h"

#include "String.h"
#include "Object.h"
#include "Class.h"

struct String *a;
struct String *b;

void setUp(void)
{
	a = new(String, "a");
	b = new(String, "a");
}
 
void tearDown(void)
{
	release(a);
	release(b);
}

void test_Differ(void)
{
	
   
}