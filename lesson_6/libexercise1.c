#include "libexercise1.h"

int Stack[SIZE];
int cursor = -1;

bool PushStack(int data)
{
	if (cursor < SIZE)
	{
		Stack[++cursor] = data;
		return true;
	}
	else
	{
		printf("Stack overflow\n");
		return false;
	}
}

int PopStack()
{
	if (cursor != -1)
		return Stack[cursor--];
	else
	{
		printf("Stack is empty\n");
		return -1;
	}
}
