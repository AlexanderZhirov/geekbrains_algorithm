#ifndef LIBLINKLIST_H_
#define LIBLINKLIST_H_

#include <stdbool.h>

typedef enum {
	L_SORTASC,
	L_SORTDESC,
	L_NOTSORT,
} lMessage;

extern lMessage lErrno;

typedef struct Node
{
	int dat;
	struct Node *next;
} Node;

typedef struct
{
	Node *head;
	int size;
} List;

List *init();
void freeList(List *);
void freeNode(Node *);

void ins(List *, int);
Node *rm(List *, int);

List *copy(List *);
void copy2(List *, List *);

void printNode(Node *);
void printList(List *);

bool checkSort(List *);
void printListMessage();

#endif
