#include "binary_trees.h"

/**
 * binary_tree_is_avl - Checks if a binary tree is an avl.
 * @tree: A pointer to the root node of the tree to count.
 *
 * Return: The number of leaves in the tree.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (ptia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * ptia_helper - helper that checks if a binary tree is an avl
 * @tree: A pointer to the root node of the tree to count.
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is avl 0otherwise.
 *
 */
int ptia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_l, path_r;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_l - path_r) > 1)
		return (0);

	return (ptia_helper(tree->left, min, tree->n - 1) &&
		ptia_helper(tree->right, tree->n + 1, max));
	/* This is part of the BST check logic */
}

/**
 * binary_tree_height - Checks the height of a binary tree
 * @tree: tree to count the height.
 *
 * Return: height of the tree otherwise NULL.
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
