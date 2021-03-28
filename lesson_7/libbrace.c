#include "libbrace.h"
#include <stdio.h>
#include "libstacklinklist.h"

bMessage bErrno;

bool checkLeftBrace(char brace)
{
	return (brace == '(' || brace == '{' || brace == '[');
}

bool checkRightBrace(char brace)
{
	return (brace == ')' || brace == '}' || brace == ']');
}

char getBraceLeftPair(char brace)
{
	switch (brace)
	{
		case '(':
			return ')';
		case '{':
			return '}';
		case '[':
			return ']';
		default:
			return brace;
	}
}

bool checkBraces(char *string, int size)
{
	Stack *stack = initStack();
	char brace;

	for (int i = 0; i < size; ++i)
	{
		brace = string[i];

		if (checkLeftBrace(brace))
			push(stack, brace);
		else if (checkRightBrace(brace))
		{
			if (stackEmpty(stack))
			{
				bErrno = BRACE_MISSINGLEFT;
				freeStack(stack);
				return false;
			}
			else if (getBraceLeftPair(pop(stack)) != brace)
			{
				bErrno = BRACE_NONCONFORMITY;
				freeStack(stack);
				return false;
			}
		}
	}

	if (!stackEmpty(stack))
	{
		bErrno = BRACE_OPENLEFT;
		freeStack(stack);
		return false;
	}

	bErrno = BRACE_CONFORMITY;
	freeStack(stack);
	return true;
}

void printBraceMessage()
{
	switch (bErrno)
	{
		case BRACE_OPENLEFT:
			puts("Есть незакрытые скобки!");
			break;
		case BRACE_MISSINGLEFT:
			puts("Отсутствуют левые открытые скобки!");
			break;
		case BRACE_NONCONFORMITY:
			puts("Неверная последовательность скобок!");
			break;
		case BRACE_CONFORMITY:
			puts("Последовательность скобок верна");
			break;
	}
}
