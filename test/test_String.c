#include "unity.h"

#include "String.h"
#include "Object.h"
#include "Class.h"

struct String *a;
struct String *b;
struct String *c;
void setUp(void)
{
	a = new(String, "a");
	b = new(String, "b");
	c = new(String, string(a));
}
 
void tearDown(void)
{
	release(a);
	release(b);
	release(c);
}

void test_Compare(void)
{
	TEST_ASSERT_EQUAL_INT(COMPARE_DIFFERENT, compare(a, b));
	TEST_ASSERT_EQUAL_INT(COMPARE_EQUAL, compare(a, a));
	
	TEST_ASSERT_EQUAL_INT(COMPARE_EQUAL, compare(a, c));
}