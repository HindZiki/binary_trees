#include "binary_trees.h"
/**
 * bst_insert - insert nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to be inserted
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tmp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				new = bst_insert(&tmp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				new = tmp->left = (bst_t *)aux;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				new = bst_insert(&tmp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				new = tmp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
