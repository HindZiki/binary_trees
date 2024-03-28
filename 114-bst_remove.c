#include "binary_trees.h"
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * two_children - function that gets the next successor using the min
 * value in the right subtree, and then replace the node value for
 * this successor
 * @root: node tat has two children
 * Return: the value found
 */
int two_children(bst_t *root)
{
	int chld_val = 0;

	chld_val = successor(root->right);
	root->n = chld_val;
	return (chld_val);
}
/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (two_children(root));
}
/**
 * bst_remove - remove node from BST tree
 * @root: root of tree
 * @value: node with this value to remove
 * Return: tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int check_removed = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		check_removed = remove_type(root);
		if (check_removed != 0)
			bst_remove(root->right, check_removed);
	}
	else
		return (NULL);
	return (root);
}
