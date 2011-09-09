#ifndef	_ARRAY_H_
#define	_ARRAY_H_

/**
  @file Array.h
  @brief Array Class used to manipulate list of items

  @author Bertrand Cachet

  @version 0.1
*/

#include "Object.h"

extern const void * Array;

//! Size memory is increased when reallocating size for the array
#define ARRAY_REALLOCATION_SIZE	8

/**
  Add an Item to the array. Added item is retained by the array.

  @param array Array that will store the Item
  @param element Item that will be stored inside array
  @return Index of the added element
*/
unsigned int array_add(void * array, void * element);

/**
  Add an Item to the array. Added item is retained by the array.

  @param array Array that will store the Item
  @param index Index of the item to remove
  @return Pointer to removed item
*/
void * array_remove(void * array, unsigned int index);

/**
  Insert an Item at a given index
  @param array Array that will store the Item
  @param element Item that will be stored inside array
  @param index Index where to store the item
*/
unsigned int array_insert(void * array, void * element, unsigned int index);

/**
  Return item stored inside array at given index
  @param array Array where the object is stored
  @param index Index where is stored the item
*/
void * array_get(void * array, unsigned int index);

/**
  Return the number of element stored inside the Array
  @return Number of elements in the array
*/
unsigned int array_count(void * array);

/**
  Return the size of the array: how many elements it can store without
  realocating memory.

  @return Size available to store elements
*/
unsigned int array_size(void * array);

void array_clear(void * array);

#endif
