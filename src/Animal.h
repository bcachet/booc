#ifndef _ANIMAL_H
#define _ANIMAL_H

typedef struct _Animal
{
    char* 		name;
    
    void (*Shout)(struct _Animal*);
	void (*Delete)(struct _Animal*);
}Animal;

Animal* Animal_New(const char* const pName);    //constructor
void Animal_Delete(Animal* const pAnimalObj);    //destructor
void Animal_Shout(Animal* const pAnimalObj);

#endif