#ifndef LIBSTACK_H_
#define LIBSTACK_H_

#include <stdbool.h> // for use boolean type

#define T int

typedef struct sNode
{
	T dat;
	struct sNode *next;
} sNode;

typedef struct
{
	sNode *head;
	int size;
} Stack;

Stack *init();
bool push(Stack *, T);
T pop(Stack *);
void printNode(sNode *);
void printStack(Stack *);
void freeStack(Stack *);

#endif
