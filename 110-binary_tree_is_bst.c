#include "binary_trees.h"
#include <stdio.h>

/**
 * greater_than - Measures if all values in the tree are greater than a value.
 * @tree: A pointer to the tree to measure.
 * @val: value to measure against.
 *
 * Return: if true,1. Otherwise 0.
 */
int greater_than(const binary_tree_t *tree, int val)
{
	int x, y;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		x = greater_than(tree->left, val);
		y = greater_than(tree->right, val);
		if (x && y)
			return (1);
	}
	return (0);
}

/**
 * less_than - Measure if all values in the tree are less than a specific value
 * @tree: A pointer to the tree to measure
 * @val: value to measure against
 *
 * Return: 1 if true, 0 if false
 */
int less_than(const binary_tree_t *tree, int val)
{
	int l, r;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		l = less_than(tree->left, val);
		r = less_than(tree->right, val);
		if (l && r)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - Measures if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_than(tree->left, tree->n) && greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}

	}
	return (0);
}

