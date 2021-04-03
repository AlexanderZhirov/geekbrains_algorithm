#ifndef LIBHW_H_
#define LIBHW_H_

#include <stdbool.h>
#include "libtree.h"

bool isBalanced(BinTreeIntNode *);
int isEmptyTree(BinTreeIntNode *);
BinTreeIntNode* searchNode(BinTreeIntNode *, int);
BinTreeIntNode* searchNode2(BinTreeIntNode *, int);

#endif
