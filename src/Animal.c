#include "Animal.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Animal* Animal_New(const char* const pName) {
	Animal *_animal = NULL;
	_animal = (Animal*)malloc(sizeof(Animal));
	_animal->name = malloc(sizeof(char)*strlen(pName));
	strcpy(_animal->name, pName);
	_animal->Delete = Animal_Delete;
	_animal->Shout = Animal_Shout;

	return _animal;
}

void Animal_Delete(Animal* const pAnimalObj) {
	if (pAnimalObj != NULL) {
		free(pAnimalObj->name);
		free(pAnimalObj);
	}
}

void Animal_Shout(Animal* const pAnimalObj) {
	printf("Animal shouting");
}