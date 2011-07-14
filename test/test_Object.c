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

void test_RefCounting(void)
{
	
	a = retain(retain(a));
	
	TEST_ASSERT_EQUAL_INT(a->ref_count, 3);
	release(a);
	release(a);
	TEST_ASSERT_EQUAL_INT(a->ref_count, 1);
	a = retain(retain(a));
	TEST_ASSERT_EQUAL_INT(a->ref_count, 3);
	release(a);
	release(a);
	TEST_ASSERT_EQUAL_INT(a->ref_count, 1);
}

void test_ReleaseDeletedObject(void) {
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