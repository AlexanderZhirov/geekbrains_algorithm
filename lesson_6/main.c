#include "libexercise1.h"
#include "libexercise2.h"

void exercise1();

void exercise2();
void intToBin(unsigned int);
void printStack();

int main(const int arc, const char **argv)
{
	exercise1();
	exercise2();

	return 0;
}

void exercise1()
{
	printf("Задание 1:\n");

	init();
	ins(1, 11);
	ins(3, 22);
	ins(4, 33);
	ins(2, 44);
	ins(3, 55);
	ins(4, 66);
	ins(5, 77);
	ins(1, 88);
	ins(2, 99);
	ins(6, 100);

	printf("Массив очереди после добавления элементов:\n");
	printQueue();

	printf("Извлечение элементов из массива очереди:\n");
	for (int i = 0; i < 7; ++i)
	{
		Node *n = rem();
		printf("pr = %d, dat = %d\n", n->pr, n->dat);
		free(n);
	}

	printf("Массив очереди после извлечения элементов:\n");
	printQueue();

	ins(1, 110);
	ins(3, 120);
	ins(6, 130);

	printf("Массив очереди после добавления элементов:\n");
	printQueue();

	printf("Извлечение элементов из массива очереди:\n");
	for (int i = 0; i < 5; ++i)
	{
		Node *n = rem();
		printf("pr = %d, dat = %d\n", n->pr, n->dat);
		free(n);
	}

	printf("Массив очереди после извлечения элементов:\n");
	printQueue();
}

void exercise2()
{
	printf("\nЗадание 2:\n");
	unsigned int num = 0;
	printf("Введите целое положительное десятичное число: ");
	scanf("%d", &num);
	intToBin(num);
	printf("Двоичное представление числа %d: ", num);
	printStack();
}

void intToBin(unsigned int n)
{
	PushStack(n % 2);
	if (n > 1)
		intToBin(n / 2);
}

void printStack()
{
	while (cursor > -1)
		printf("%d", PopStack());
}

