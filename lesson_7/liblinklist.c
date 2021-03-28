#include "liblinklist.h"
#include <stdlib.h>
#include <stdio.h>

lMessage lErrno;

List *init()
{
	List *lst = (List *)malloc(sizeof(List));
	lst->head = NULL;
	lst->size = 0;
	return lst;
}

void ins(List *lst, int data)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;

	Node *current = lst->head;
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

Node *rm(List *lst, int data)
{
	Node *current = lst->head;
	Node *parent = NULL;
	if (current == NULL)
		return NULL;

	while (current->next != NULL && current->dat != data)
	{
		parent = current;
		current = current->next;
	}
	if (current->dat != data)
		return NULL;
	if (current == lst->head)
	{
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

void freeList(List *lst)
{
	if (lst->size)
		freeNode(lst->head);
	free(lst);
}

void freeNode(Node *n)
{
	if (n->next)
		freeNode(n->next);
	free(n);
}

void printNode(Node *n)
{
	if (n == NULL)
	{
		printf("[]");
		return;
	}
	printf("[%d] ", n->dat);
}

void printList(List *lst)
{
	if (lst == NULL)
	{
		printf("List not defined\n");
	}
	else
	{
		Node *current = lst->head;
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
		printf(" Size: %d\n", lst->size);
	}
}

List *copy(List *lst)
{
	List *newLst = init();
	newLst->size = lst->size;

	Node **head = &(newLst->head);

	for (Node *node = lst->head; node != NULL; node = node->next, head = &((*head)->next))
	{
		Node *new = (Node *)malloc(sizeof(Node));
		new->dat = node->dat;
		*head = new;
	}

	return newLst;
}

bool checkSort(List *lst)
{
	int tmp;       // Предыдущее сравниваемое значение
	int asc = 0;   // Счётчик сортировки по возрастанию
	int desc = 0;   // Счётчик сортировки по убыванию
	int items = 0; // Счётчик общего количества элементов

	if (lst->size)
	{
		tmp = lst->head->dat;

		for (Node *node = lst->head; node != NULL; node = node->next)
		{
			if (asc == -1 && desc == -1)
				break;

			items++;

			if (asc != -1 && node->dat >= tmp)
				asc++;

			if (desc != -1 && node->dat <= tmp)
				desc++;

			tmp = node->dat;

			// При условии, если огромное количество элементов,
			// то при ближайшей ошибке в сортировке прервать цикл
			if (items != asc)
				asc = -1;
			if (items != desc)
				desc = -1;
		}

		if (lst->size == asc)
			lErrno = L_SORTASC;
		else if (lst->size == desc)
			lErrno = L_SORTDESC;
		else
			lErrno = L_NOTSORT;

		return (lst->size == asc || lst->size == desc);
	}
	else
	{
		lErrno = L_NOTSORT;
		return false;
	}
}

void printListMessage()
{
	switch (lErrno)
	{
		case L_SORTASC:
			puts("Связной список отсортирован по возрастанию");
			break;
		case L_SORTDESC:
			puts("Связной список отсортирован по убыванию");
			break;
		case L_NOTSORT:
			puts("Связной список не отсортирован");
			break;
	}
}
