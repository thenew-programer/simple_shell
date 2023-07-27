#include "main.h"
/**
 * This function fills a block of memory with a specified value.
 * @ptr: Pointer to the memory block to be filled.
 * @value: Value to be set in the memory block.
 * @num: Number of bytes to be filled.
 * Return: Pointer to the memory block.
 */
char *_memset(char *ptr, char value, unsigned int num)
{
	unsigned int count = 0;

	while (count < num)
	{
		*(ptr + count) = value;
		count++;
	}
	return (ptr);
}
/**
 * This function allocates memory for an array and initializes it to zero.
 * @numElements: Number of elements in the array.
 * @elementSize: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory block.
 */
void *_calloc(unsigned int numElements, int elementSize)
{
	void *ptr = NULL;

	if (numElements == 0 || elementSize == 0)
		return (NULL);
	ptr = malloc(numElements * elementSize);

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, elementSize * numElements);
	return (ptr);
}