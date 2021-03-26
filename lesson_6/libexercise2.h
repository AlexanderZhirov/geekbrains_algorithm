#ifndef LIBEXERCISE2_H_
#define LIBEXERCISE2_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SZ 10
typedef struct
{
	int pr;
	int dat;
} Node;

extern Node *arr[SZ];
extern int head;        // Голова очереди
extern int tail;        // Хвост очереди
extern int items;       // Количество элементов

void init();
void ins(int, int);
Node *rem();
void printQueue();

#endif
