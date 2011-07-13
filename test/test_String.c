#include "unity.h"

#include "String.h"
#include "String.r"
#include "new.h"

struct String *a;
struct String *b;

void setUp(void)
{
	a = new(String, "a");
	b = new(String, "a");
}
 
void tearDown(void)
{
	delete(a);
	delete(b);
}

void test_Differ(void)
{
	
    TEST_ASSERT(!differ(a, b));
}