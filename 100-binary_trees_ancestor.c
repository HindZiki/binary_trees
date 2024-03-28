#include "binary_trees.h"

/**
 * binary_trees_ancestor - function check ancestor of btree
 * @first: First node var
 * @second: Second node var
 * Return: node of ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *prnt, *q;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	prnt = first->parent;
	q = second->parent;
	if (prnt == NULL || first == q || (!prnt->parent && q))
	{
		return (binary_trees_ancestor(first, q));
	}
	else if (q == NULL || prnt == second || (!q->parent && prnt))
	{
		return (binary_trees_ancestor(prnt, second));
	}
	return (binary_trees_ancestor(prnt, q));
}
