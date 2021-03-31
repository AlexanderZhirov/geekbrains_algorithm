#ifndef LIBSTACKLINKLIST_H_
#define LIBSTACKLINKLIST_H_

#include <stdbool.h>

#define T char
#define EMPTYSTACK -1

typedef struct Node
{
	T dat;
	struct Node *next;
} Node;

typedef struct
{
	Node *head;
	int size;
} Stack;

Stack *initStack();
void freeStack(Stack *);

bool push(Stack *, T);
T pop(Stack *);
bool stackEmpty(Stack *);

#endif
