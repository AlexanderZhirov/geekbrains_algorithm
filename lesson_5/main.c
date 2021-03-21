#include <stdio.h>
#include "libf.h"

void exercise1();
void exercise2();

int main(const int argc, const char **argv)
{
	exercise1();
	exercise2();

	return 0;
}

void exercise1()
{
	printf("Улучшенная быстрая сортировка:\n");
	const int SZ = 10;
	const int offset = 4;
	const int randNum = 999;
	int arr[SZ];
	fillRandom(arr, SZ, randNum);
	printArray(arr, SZ, offset);
	improvedQuickSort(arr, 0, SZ - 1);
	printArray(arr, SZ, offset);
}

void exercise2()
{
	printf("Алгоритм блочной сортировки четных чисел:\n");
	const int SZ = 10;
	const int offset = 4;
	const int randNum = 999;
	int arr[SZ];
	fillRandom(arr, SZ, randNum);
	printArray(arr, SZ, offset);
	evenBucketSort(arr, SZ);
	printArray(arr, SZ, offset);
}
