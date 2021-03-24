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
	int curRow, curCol;

	for (int k = 0; k < (row * col - 1); ++k)
		for (int i = 0; i < row;)
		{
			curRow = i;
			for (int j = 0; j < col;)
			{
				curCol = j++;
				if (j == col)
				{
					++i;
					if (i == row)
						continue;
				}

				if (array[curRow][curCol] > array[i][j % col])
					swapInt(&array[curRow][curCol], &array[i][j % col]);
			}
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


