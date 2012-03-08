#include "unity.h"

#include "Class.h"
#include "Object.h"
#include "String.h"

struct String *a;
struct String *b;
struct String *c;
void setUp(void)
{
	a = (struct String*)new(ClassString, "a");
	b = (struct String*)new(ClassString, "b");
	c = (struct String*)new(ClassString, string(a));
}
 
void tearDown(void)
{
	release((struct Object *)a);
	release((struct Object *)b);
	release((struct Object *)c);
}

void test_CompareDifferentObjects(void)
{
	TEST_ASSERT_EQUAL_INT(COMPARE_DIFFERENT, compare(a, b));
}

void test_CompareSameObject(void) {
	TEST_ASSERT_EQUAL_INT(COMPARE_EQUAL, compare(a, a));
}

void test_CompareDifferentObjectsSameString(void)
{	
	TEST_ASSERT_EQUAL_INT(COMPARE_EQUAL, compare(a, c));
}
