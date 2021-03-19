#include <stdio.h>
#include <math.h>
#include "secondary_functions.h"

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
	const int sizeX = 4;
	const int sizeY = 3;
	int arr[sizeX][sizeY];
	fillRandom(sizeX, sizeY, arr, 50);
	printf("Исходный массив:\n");
	printIntArray(sizeX, sizeY, arr);
	bubbleSort(sizeX, sizeY, arr);
	printf("Отсортированный массив:\n");
	printIntArray(sizeX, sizeY, arr);
}

void exercise2()
{
	const int size = 11;
	float arr[size], calc;

	for (int i = 0; i < size; i++)
	{
		printf("Введите число №%d: ", i + 1);
		scanf("%f", &arr[i]);
	}
	
	for (int i = 0; i < size; i++)
	{
		calc = sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3);

		if (calc > 400)
			printf("Расчет числа №%d превышает 400\n", i + 1);
	}
}

