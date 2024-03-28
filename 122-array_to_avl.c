#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from arr
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, cnt = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (cnt = 0; cnt < i; cnt++)
		{
			if (array[cnt] == array[i])
				break;
		}
		if (cnt == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
