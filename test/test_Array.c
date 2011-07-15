#include "unity.h"

#include "Array.h"
#include "Object.h"
#include "Class.h"

struct Array *a;
struct Object *o;
void setUp(void)
{
	a = new(Array, 1);
	o = new(Object);
}
 
void tearDown(void)
{
	release(a);
	release(o);
}

void test_AddCount(void) {
	TEST_ASSERT_EQUAL_INT(array_count(a), 0);
	array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), 1);
}

void test_AddWithMemoryReallocation(void) {
	TEST_ASSERT_EQUAL_INT(array_count(a), 0);
	TEST_ASSERT_EQUAL_INT(array_size(a), 1);
	TEST_ASSERT_EQUAL_INT(array_add(a, o), 0);
	TEST_ASSERT_EQUAL_INT(array_count(a), 1);
	TEST_ASSERT_EQUAL_INT(array_size(a), 1);
	TEST_ASSERT_EQUAL_INT(array_add(a, o), 1);
	TEST_ASSERT_EQUAL_INT(array_count(a), 2);
	TEST_ASSERT(array_size(a) > 2);
}

void test_Remove(void) {
	TEST_ASSERT_EQUAL_INT(array_count(a), 0);
	int index = array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), 1);
	struct Object* item = array_remove(a, index);
	TEST_ASSERT(compare(item, o) == COMPARE_EQUAL);
}
