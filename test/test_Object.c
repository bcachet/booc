#include "unity.h"

#include "Object.h"
#include "Object.r"
#include "Class.h"
#include "CException.h"

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

void test_Retain(void)
{
	int ref_count = a -> ref_count;
	a = retain(retain(a));
	ref_count += 2;
	TEST_ASSERT_EQUAL_INT(a->ref_count, ref_count);
	release(a);
	release(a);
	ref_count -= 2;
	TEST_ASSERT_EQUAL_INT(a->ref_count, ref_count);
	a = retain(retain(a));
	ref_count += 2;
	TEST_ASSERT_EQUAL_INT(a->ref_count, ref_count);
	release(a);
	release(a);
	ref_count -= 2;
	TEST_ASSERT_EQUAL_INT(a->ref_count, ref_count);

	struct Object *c = new(Object);
	release(c);
	CEXCEPTION_T e;
	Try {
		release(c);
		TEST_FAIL_MESSAGE("Should have raised an exception");
	}
	Catch(e) {
		TEST_ASSERT_EQUAL_INT(e, OBJECT_RELEASE_DELETED_OBJECT);
	}
}