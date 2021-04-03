#ifndef LIBLIST_H_
#define LIBLIST_H_

#include <stdbool.h>
#include "libtree.h"

#define T BinTreeIntNode *

typedef struct lNode
{
	T dat;
	struct lNode *next;
} lNode;

typedef struct
{
	lNode *head;
	int size;
} List;

List *initList();
void addNode(List *, T);
T rmNode(List *);
void freeList(List *);

#endif
