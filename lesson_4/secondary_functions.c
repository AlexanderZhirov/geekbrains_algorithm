#include "secondary_functions.h"
#include <stdlib.h>
#include <stdio.h>

void swapInt(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swapFloat(float *a, float *b)
{
	float t = *a;
	*a = *b;
	*b = t;
}

void bubbleSort(const int row, const int col, int array[][col])
{
	for (int i = 0; i < (row * col - 1); ++i)
		for (int i = 0; i < row; ++i)
			for (int j = 1; j <= col; ++j)
			{
				if (i == (row - 1) && j == col)
					continue;

				if (array[i][j - 1] > array[i][j])
					swapInt(&array[i][j - 1], &array[i][j]);
			}
}

void fillRandom(const int row, const int col, int array[][col], const int border)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			array[i][j] = rand() % border;
}

void printIntArray(const int row, const int col, int array[][col])
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			printf("[%d]", array[i][j]);
		printf("\n");
	}
}


