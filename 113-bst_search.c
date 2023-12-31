#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	tmp = (bst_t *)tree;
	while (tmp)
	{
		if (tmp->n == value)
			return (tmp);
		if (tmp->n < value)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}
