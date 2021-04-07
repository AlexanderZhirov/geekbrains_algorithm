#include "libarray.h"
#include <stdlib.h>
#include <stdio.h>

int get2dInt(int** array, const int row, const int col)
{
    return *((*(array + row)) + col);
}

void set2dInt(int** array, const int row, const int col, int value)
{
    *((*(array + row)) + col) = value;
}

int **init2dIntArray(const int row, const int col)
{
	int **array = (int **)calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i)
        *(array + i) = (int *)calloc(sizeof(int), col);
    return array;
}
void print2dIntArray(int** array, const int row, const int col, int offset)
{
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            printf(format, get2dInt(array, i, j));
        printf("\n");
    }
}

void free2dIntArray(int** array, const int row, const int col)
{
    for (int i = 0; i < row; ++i)
        free(array[i]);
    free(array);
}

void printIntArray(int* array, int size, int offset)
{
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void clearIntArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}
