#include "binary_trees.h"
/**
 * bst_search - search for a special value in tree and return node
 * @tree: tree to go through
 * @value: value to search
 * Return: node with value or NULL if value is not in tree
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *flag;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		flag = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		flag = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (flag);
}
