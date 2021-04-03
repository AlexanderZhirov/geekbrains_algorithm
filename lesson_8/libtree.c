#include "libtree.h"
#include <stdlib.h>

BinTreeIntNode* treeInsert(BinTreeIntNode *t, int data)
{
    BinTreeIntNode *newNode;
    newNode = (BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    BinTreeIntNode *current = t;
    BinTreeIntNode *parent = t;
    if (t == NULL)
        t = newNode;
    else
    {
        while (true)
        {
			parent = current;
			if (current->key > data)
			{
				current = current->left;
				if (current == NULL)
				{
					parent->left = newNode;
					return t;
				}
			}
			else
			{
				current = current->right;
				if (current == NULL)
				{
					parent->right = newNode;
					return t;
				}
			}
        }
    }
    return t;
}

void printBinTree(BinTreeIntNode *root)
{
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right)
        {
            printf("(");
            if (root->left)
                printBinTree(root->left);
            else
                printf("NULL");
            printf(",");
            if (root->right)
                printBinTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

void freeBinTree(BinTreeIntNode *node)
{
	if (node != NULL)
	{
		freeBinTree(node->right);
		freeBinTree(node->left);
		free(node);
	}
}
