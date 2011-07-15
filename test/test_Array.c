#include "unity.h"

#include "Array.h"
#include "Object.h"
#include "Class.h"

struct Array *a;
struct Object *o;

#define INIT_ARRAY_SIZE	1

void setUp(void)
{
	a = new(Array, INIT_ARRAY_SIZE);
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
	array_add(a, o);
	array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), 3);
}

void test_AddWithMemoryReallocation(void) {
	TEST_ASSERT_EQUAL_INT(array_count(a), 0);
	TEST_ASSERT_EQUAL_INT(array_size(a), INIT_ARRAY_SIZE);
	int i = 0;
	for (i = 0; i <= INIT_ARRAY_SIZE; i++)
		array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), INIT_ARRAY_SIZE + 1);
	TEST_ASSERT_EQUAL_INT(array_size(a), INIT_ARRAY_SIZE + ARRAY_REALLOCATION_SIZE);
}

void test_Remove(void) {
	TEST_ASSERT_EQUAL_INT(array_count(a), 0);
	int index = array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), 1);
	struct Object* item = array_remove(a, index);
	TEST_ASSERT(compare(item, o) == COMPARE_EQUAL);
}

void test_Insert(void) {
	struct Object *b = new(Object);
	array_add(a, o);
	TEST_ASSERT_EQUAL_INT(array_count(a), 1);
	TEST_ASSERT_EQUAL_INT(array_insert(a, b, 0), 0);
	TEST_ASSERT_EQUAL_INT(array_count(a), 2);
	TEST_ASSERT_EQUAL_INT(array_insert(a, o, 2), 2);
	TEST_ASSERT_EQUAL_INT(array_count(a), 3);
	TEST_ASSERT_EQUAL_INT(array_insert(a, o, 3), 3);
	TEST_ASSERT(compare(array_get(a, 0), b) == COMPARE_EQUAL);
	TEST_ASSERT(compare(array_get(a, 2), o) == COMPARE_EQUAL);
	TEST_ASSERT(compare(array_get(a, 1), o) == COMPARE_EQUAL);
	release(b);
}
