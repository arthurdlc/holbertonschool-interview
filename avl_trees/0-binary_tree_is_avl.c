#include "binary_trees.h"
#include <limits.h>

/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node
 * Return: height or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
if (!tree)
return (0);

int left_h = height(tree->left);
int right_h = height(tree->right);
// ce betty de merde commmence a me les brissé menu

return (1 + (left_h > right_h ? left_h : right_h));
}

/**
 * is_bst - checks if a binary tree is a valid BST
 * @tree: pointer to the root
 * @min: minimum allowed value
 * @max: maximum allowed value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (!tree)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

return (is_bst(tree->left, min, tree->n) &&
is_bst(tree->right, tree->n, max));
}

/**
 * is_avl_helper - recursively checks if tree is AVL
 * @tree: pointer to root
 * @min: min value allowed
 * @max: max value allowed
 * Return: 1 if AVL, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
int balance;

if (!tree)
return (1);

if (tree->n <= min || tree->n >= max)
return (0);

int lh = height(tree->left);
int rh = height(tree->right);

balance = lh - rh;
if (balance > 1 || balance < -1)
return (0);

return (is_avl_helper(tree->left, min, tree->n) &&
is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node
 * Return: 1 if tree is valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (!tree)
return (0);

return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
