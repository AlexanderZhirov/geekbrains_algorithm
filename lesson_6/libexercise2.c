#include "libexercise2.h"

Node *arr[SZ];
int head;
int tail;
int items;

void init()
{
	for (int i = 0; i < SZ; ++i)
		arr[i] = NULL;

	head = 0;
	tail = -1;
	items = 0;
}

void ins(int pr, int dat)
{
	if (items == SZ)
		printf("Queue is full\n");
	else
	{
		Node *node = (Node *)malloc(sizeof(Node));
		node->dat = dat;
		node->pr = pr;

		arr[++tail] = node;
		items++;
	}
}

Node *rem()
{
	if (items == 0)
	{
		printf("Queue is empty\n");
		return NULL;
	}
	else
	{
		int idx = head;
		int flag = 0;
		Node *tmp = arr[head];

		while (++idx < items)
			if (tmp->pr > arr[idx]->pr)
			{
				tmp = arr[idx];
				flag = idx;
			}

		idx = flag;

		while (flag < items)
			arr[flag++] = arr[++idx];

		arr[tail--] = NULL;
		--items;

		return tmp;
	}
}

void printQueue()
{
	printf("[ ");
	for (int i = 0; i < SZ; ++i)
	{
		if (arr[i] == NULL)
			printf("[*, *] ");
		else
			printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
	}
	printf(" ]\n");
}
