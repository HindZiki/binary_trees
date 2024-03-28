#include "binary_trees.h"
/**
 * aux_sort - create tree using half element of array
 * @parent: parent of node to create
 * @array: sorted array
 * @begin: position where array starts
 * @last: position where array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int tmedian = 0;

	if (begin <= last)
	{
		tmedian = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[tmedian]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, tmedian - 1);
		root->right = aux_sort(root, array, tmedian + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - create alv tree from sorted array
 * @array: sorted array
 * @size: size of sorted array
 * Return: alv tree form sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
