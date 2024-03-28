#include "binary_trees.h"

/**
 * array_to_heap - builds Max Binary Heap tree from an array
 * @array: a pointer to first element of array to convert
 * @size: num of element in array
 *
 * Return: pointer to root node of created Heap
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int ct;
	heap_t *root = NULL;

	for (ct = 0; ct < size; ct++)
		heap_insert(&root, array[ct]);

	return (root);
}