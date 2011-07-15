#ifndef	_ARRAY_H_
#define	_ARRAY_H_

//! Array Class
/**
	Used to manipulate Items in an Array.
*/

extern const void * Array;

//! Size memory is increased when reallocating size for the array
#define ARRAY_REALLOCATION_SIZE	8

/**
	Add an Item to the array. Added item is retained by the array.

	\param array Array that will store the Item
	\param element Item that will be stored inside array	
	\return index where the Item was stored
*/
unsigned int array_add(void * array, void * element);

/**
	Add an Item to the array. Added item is retained by the array.

	\param array Array that will store the Item
	\param index Index of the item to remove
	\return Pointer to removed item
*/
void * array_remove(void * array, unsigned int index);

/**
	Return the number of element stored inside the Array
*/
unsigned int array_count(void * array);

/**
	Return the size of the array: how many elements it can store without
	realocating memory.
*/
unsigned int array_size(void * array);

#endif