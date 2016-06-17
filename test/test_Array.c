#include <time.h>

#include "unity.h"

#include "Array.h"
#include "Object.h"
#include "Class.h"


#include "Array.r"

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
	TEST_ASSERT_EQUAL_INT(a -> count(a), 0);
	a -> add(a, o);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 1);
	a -> add(a, o);
	a -> add(a, o);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 3);
}

void test_AddWithMemoryReallocation(void) {
	TEST_ASSERT_EQUAL_INT(a -> count(a), 0);
	TEST_ASSERT_EQUAL_INT(a -> size(a), INIT_ARRAY_SIZE);
	int i = 0;
	for (i = 0; i <= INIT_ARRAY_SIZE; i++)
		a -> add(a, o);
	TEST_ASSERT_EQUAL_INT(a -> count(a), INIT_ARRAY_SIZE + 1);
	TEST_ASSERT_EQUAL_INT(a -> size(a), INIT_ARRAY_SIZE + ARRAY_REALLOCATION_SIZE);
}

void test_Remove(void) {
	TEST_ASSERT_EQUAL_INT(a -> count(a), 0);
	a -> add(a, o);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 1);
	struct Object* item = a -> remove(a, 0);
	TEST_ASSERT(compare(item, o) == COMPARE_EQUAL);
}

void test_Insert(void) {
	struct Array *b = new(Object);
	a -> add(a, o);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 1);
	TEST_ASSERT_EQUAL_INT(a -> insert(a, b, 0), 0);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 2);
	TEST_ASSERT_EQUAL_INT(a -> insert(a, o, 2), 2);
	TEST_ASSERT_EQUAL_INT(a -> count(a), 3);
	TEST_ASSERT_EQUAL_INT(a -> insert(a, o, 3), 3);
	TEST_ASSERT(compare(a -> get(a, 0), b) == COMPARE_EQUAL);
	TEST_ASSERT(compare(a -> get(a, 2), o) == COMPARE_EQUAL);
	TEST_ASSERT(compare(a -> get(a, 1), o) == COMPARE_EQUAL);
	release(b);
}

unsigned int add(struct Array * self, void * element) {
	if(self -> _count >= self -> _size) {
		array_reallocateMemory(self);
	}
	self -> _objects[self -> _count] = element;
	self -> _count ++;
#ifdef REFERENCE_COUNTING
  self -> _objects[self -> _count] = retain(element);
#endif	
  return self -> count - 1;
}

void test_Performance() {
	fprintf(stderr, "test_Performance comparison\n");
	const int size = 10240;

	struct Array *array = new(Array, size);
	struct Object *obj = new(Object);
	int i = 0;
	time_t start;
	start = clock();
	for (i = 0; i < size; i++) {
		add(array, obj);
	}
	fprintf(stderr, "Reference :: Elapsed time: %lu\n", clock() - start);
  array -> count = 0;
  start = clock();
	for (i = 0; i < size; i++) {
		array -> add(array, obj);
	}
	fprintf(stderr, "Using Array Class :: Elapsed time: %lu\n", clock() - start);
	array -> clear(array);


	release(array);
	release(obj);
}

void test_Clone() {
  void *c = clone(a);
  TEST_ASSERT_EQUAL_INT(COMPARE_EQUAL, compare(c, a));
  release(c);
}


