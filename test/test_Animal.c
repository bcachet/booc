#include "unity.h"
#include "Animal.h"

Animal *dog;

void setUp(void)
{
	dog = Animal_New("Aika");
}
 
void tearDown(void)
{
	dog->Delete(dog);
}

void test_Shout(void)
{
	
    TEST_ASSERT_EQUAL_STRING(dog->name, "Aika");
}