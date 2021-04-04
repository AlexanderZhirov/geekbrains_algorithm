#include "libhw.h"
#include <limits.h>
#include "liblist.h"

#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MAX(a, b) ((a) > (b))

bool isBalanced(BinTreeIntNode *root)
{
	if (root == NULL)
		return true;

	int level = 1, minLevel = INT_MAX, maxLevel = INT_MIN;
	List *list = initList();
	addNode(list, root);

	while (list->size)
	{
		int elementCount = list->size;
		while (elementCount > 0)
		{
			BinTreeIntNode *node = rmNode(list);
			if (isEmptyTree(node))
			{
				if (minLevel > level)
					minLevel = level;
				if (maxLevel < level)
					maxLevel = level;
			}
			else
			{
				if (node->left != NULL)
					addNode(list, node->left);
				if (node->right != NULL)
					addNode(list, node->right);
			}
			elementCount--;
		}

		if (ABS(maxLevel - minLevel) > 1)
		{
			freeList(list);
			return false;
		}
		level++;
	}
	freeList(list);
	return true;
}

int isEmptyTree(BinTreeIntNode *root)
{
	if (root->left == NULL && root->right == NULL)
		return true;
	return false;
}

BinTreeIntNode* searchNode(BinTreeIntNode *root, int data)
{
	if (root == NULL)
		return NULL;

	if (root->key > data)
		return searchNode(root->left, data);
	else if (root->key < data)
		return searchNode(root->right, data);
	else
		return root;
}

BinTreeIntNode* searchNode2(BinTreeIntNode *root, int data)
{
	if (root == NULL)
		return NULL;

	List *list = initList();
	addNode(list, root);

	while (list->size)
	{
		int elementCount = list->size;
		while (elementCount > 0)
		{
			BinTreeIntNode *node = rmNode(list);

			if (node->key == data)
			{
				freeList(list);
				return node;
			}
			else
			{
				if (node->left != NULL)
					addNode(list, node->left);
				if (node->right != NULL)
					addNode(list, node->right);
			}
			elementCount--;
		}
	}
	freeList(list);

	return NULL;
}
