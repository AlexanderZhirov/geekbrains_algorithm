#include <stdio.h>
#include <stdlib.h>
#include "libstack.h"

Stack *init()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->head = NULL;
	stack->size = 0;
	return stack;
}

bool push(Stack *stack, T value)
{
	sNode *tmp = (sNode *)malloc(sizeof(sNode));
	if (tmp == NULL)
	{
		printf("Stack overflow\n");
		return false;
	}
	tmp->dat = value;
	tmp->next = stack->head;

	stack->head = tmp;
	stack->size++;
	return true;
}

T pop(Stack *stack)
{
	if (stack->size == 0)
	{
		printf("Stack is empty\n");
		return -1;
	}
	sNode *tmp = stack->head;
	T data = stack->head->dat;
	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}

void freeStack(Stack *stack)
{
	sNode *head = stack->head;

	while (head)
	{
		sNode *fNode = head;
		head = head->next;
		free(fNode);
	}

	free(stack);
}

void printNode(sNode *n)
{
	if (n == NULL)
	{
		printf("[]");
		return;
	}
	printf("[%c] ", n->dat);
}

void printStack(Stack *stack)
{
	sNode *current = stack->head;
	if (current == NULL)
		printNode(current);
	else
	{
		do
		{
			printNode(current);
			current = current->next;
		} while (current != NULL);
	}
	printf(" Size: %d\n", stack->size);
}
