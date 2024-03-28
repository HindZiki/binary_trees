#include "binary_trees.h"
/**
 * check_sub_tree_Left - check if all node smaller than the root
 * @node: node in the tree to verify condition
 * @max: value to be compared
 * Return: 1 if all nodes are smaller or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int lft = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		lft = check_sub_tree_Left(node->lft, max);
		right = check_sub_tree_Left(node->right, max);
		if (lft == right && lft == 1)
			return (1);
		return (0);
	}
}
/**
 * check_sub_tree_Right - check if nodes are bigger than root
 * @node: node in the tree to verify condition
 * @min: value to compare
 * Return: 1 if is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int lft = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		lft = check_sub_tree_Right(node->lft, min);
		right = check_sub_tree_Right(node->right, min);
		if (lft == right && lft == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - says if a tree is a bst or not
 * @tree: node that point to tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
