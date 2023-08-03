#include "binary_trees.h"

/**
 * sorted_array_to_avl - Creates an AVL tree
 * @array: pointer node
 * @size: size of array
 *
 * Return: no return
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	pata_helper(&tree, array, -1, middle);
	pata_helper(&tree, array, middle, size);

	return (tree);
}

/**
 * pata_helper - helper that creates an AVL tree.
 * @root: A double pointer to the root node of the subtree
 * @array: input array of integers
 * @lo: lower index
 * @hi: upper index
 */
void pata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		pata_helper(&new, array, lo, middle);
		pata_helper(&new, array, middle, hi);
	}
}

