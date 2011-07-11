#include "unity.h"
#include "Animal.h"

void setUp(void)
{
}
 
void tearDown(void)
{
}

void test_Shout(void)
{
	Animal *dog = Animal_New("Aika");
    TEST_ASSERT_EQUAL_STRING(dog->name, "Aika");
}