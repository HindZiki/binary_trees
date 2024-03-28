#include "binary_trees.h"

/**
 * bal - Measures balance factor of  AVL
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bvalue;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bvalue = binary_tree_balance((const binary_tree_t *)*tree);
	if (bvalue > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bvalue < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
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
 *remove_type - function removes  node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value
 */
int remove_type(bst_t *root)
{
	int nval = 0;

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
	{
		nval = successor(root->right);
		root->n = nval;
		return (nval);
	}
}
/**
 * bst_remove - remove node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove node from a AVL tree
 * @root: root of tree
 * @value: node with this value to remove
 * Return: tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_t = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_t == NULL)
		return (NULL);
	bal(&root_t);
	return (root_t);
}
