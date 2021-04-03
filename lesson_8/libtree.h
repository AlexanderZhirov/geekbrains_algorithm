#ifndef LIBTREE_H_
#define LIBTREE_H_

#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeIntNode;

BinTreeIntNode* treeInsert(BinTreeIntNode *, int);
void printBinTree(BinTreeIntNode *);
void freeBinTree(BinTreeIntNode *);

#endif
