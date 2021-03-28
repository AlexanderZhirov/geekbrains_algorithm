#include <stdio.h>
#include <stdlib.h>
#include "libbrace.h"
#include "liblinklist.h"

#define SIZE 12

void exercise_1();
void exercise_2_3();

int main(const int arc, const char **argv)
{
	exercise_1();
	exercise_2_3();

	return 0;
}

void exercise_1()
{
	printf("Задание 1\n");
	char str1[SIZE] = "(2+(2*2))";
	printf("%s - ", checkBraces(str1, SIZE) ? "true" : "false");
	printBraceMessage(); // Для получения информации об имеющейся ошибке
	char str2[SIZE] = "{2/{5*(4+7)]";
	printf("%s - ", checkBraces(str2, SIZE) ? "true" : "false");
	printBraceMessage(); // Для получения информации об имеющейся ошибке
}

void exercise_2_3()
{
	printf("\nЗадание 2 и 3\n");
	List *lst1 = init();
	ins(lst1, 123);
	ins(lst1, 653);
	ins(lst1, 947);
	printList(lst1);

	List *lst2 = copy(lst1);
	printList(lst2);
	printf("%s - ", checkSort(lst2) ? "true" : "false");
	printListMessage();
	ins(lst2, 453);
	printList(lst2);
	printf("%s - ", checkSort(lst2) ? "true" : "false");
	printListMessage();

	free(rm(lst1, 123));
	printList(lst1);
	printList(lst2);

	free(rm(lst2, 947));
	printList(lst1);
	printList(lst2);

	free(rm(lst2, 123));
	free(rm(lst2, 653));
	ins(lst2, 452);
	ins(lst2, 321);
	printList(lst2);
	printf("%s - ", checkSort(lst2) ? "true" : "false");
	printListMessage();

	freeList(lst1);
	freeList(lst2);
}
