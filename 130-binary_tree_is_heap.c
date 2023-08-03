#include "binary_trees.h"

/**
 * binary_tree_is_heap - Measures if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: 1 if all nodes are max, 0 in other cases
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (ptih_helper(tree));
}

/**
 * ptih_helper - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         1 if tree is NULL
 *         0 otherwise
 */
int ptih_helper(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!binary_tree_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (ptih_helper(tree->left) &&
		ptih_helper(tree->right));
}

/**
 * binary_tree_is_complete - Measures if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: 1 if the tree is complete otherwise NULL.
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (btic_helper(tree, 0, size));
}

/**
 * ptic_helper - checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete Otherwise not complete or NULL.
 *
 */
int ptic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (ptic_helper(tree->left, 2 * index + 1, size) &&
		ptic_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to check the size of
 *
 * Return: size of the tree otherwise 0 if NULL.
 *
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

