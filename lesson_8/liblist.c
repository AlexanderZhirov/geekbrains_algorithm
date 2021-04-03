#include "liblist.h"
#include <stdlib.h>
#include <stdio.h>

List *initList()
{
	List *lst = (List *)malloc(sizeof(List));
	lst->head = NULL;
	lst->size = 0;
	return lst;
}

void addNode(List *lst, T data)
{
	lNode *new = (lNode *)malloc(sizeof(lNode));
	new->dat = data;
	new->next = NULL;

	lNode *current = lst->head;
	if (current == NULL)
	{
		lst->head = new;
		lst->size++;
		return;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		lst->size++;
	}
}

T rmNode(List *lst)
{
	if (lst->head == NULL)
		return NULL;

	T dat = lst->head->dat;
	lNode *current = lst->head;
	lst->head = current->next;
	lst->size--;

	free(current);

	return dat;
}

void freeList(List *lst)
{
	while (lst->size)
		rmNode(lst);
	free(lst);
}
