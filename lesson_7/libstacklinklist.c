#include "libstacklinklist.h"
#include <stdlib.h>
#include <stdio.h>

Stack *initStack()
{
	Stack *st = (Stack *)malloc(sizeof(Stack));
	st->head = NULL;
	st->size = 0;
	return st;
}

void freeStack(Stack *stack)
{
	while (stack->size--)
	{
		Node *tmp = stack->head;
		stack->head = tmp->next;
		free(tmp);
	}

	free(stack);
}

bool push(Stack *stack, T value)
{
	Node *tmp = (Node *)malloc(sizeof(Node));
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
	if (stackEmpty(stack))
	{
		printf("Stack is empty\n");
		return EMPTYSTACK;
	}
	Node *tmp = stack->head;
	T data = stack->head->dat;
	stack->head = stack->head->next;
	stack->size--;
	free(tmp);
	return data;
}

bool stackEmpty(Stack *stack)
{
	return stack->size == 0;
}
