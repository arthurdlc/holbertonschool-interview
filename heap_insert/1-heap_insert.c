#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify_up - Restores the Max Heap property by swapping nodes upward
 * @node: Pointer to the node to heapify
 *
 * Return: Pointer to the node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	heap_t *parent;
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		parent = node->parent;

		/* Swap values */
		temp = node->n;
		node->n = parent->n;
		parent->n = temp;

		/* Move up */
		node = parent;
	}

	return (node);
}

/**
 * find_insertion_point - Finds the insertion point in a Max Heap
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent where the new node should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
	heap_t *queue[1024];
	int head = 0, tail = 0;

	queue[tail++] = root;

	while (head < tail)
	{
		heap_t *current = queue[head++];

		/* Return the first node with an available child */
		if (!current->left || !current->right)
			return (current);

		/* Add children to the queue */
		queue[tail++] = current->left;
		queue[tail++] = current->right;
	}

	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the insertion point */
	parent = find_insertion_point(*root);

	/* Create the new node and attach it to its parent */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Restore the Max Heap property */
	return (heapify_up(new_node));
}
