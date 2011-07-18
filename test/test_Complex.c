#include "unity.h"

#include "Complex.h"
#include "Complex.r"
#include "Object.h"
#include "Class.h"

struct Complex *z;

void setUp(void) {
	z = new(Complex, 2.0f, 2.0f);
}
 
void tearDown(void)
{
	release(z);
}

void test_Absolute(void)
{
	TEST_ASSERT_EQUAL(2, absolute(z));
}
