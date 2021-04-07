#include "libhw.h"
#include "libstack.h"
#include <stdio.h>
#include <stdlib.h>

void clearArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    	arr[i] = 0;
}

void depthFirstTraverse(int **graphs, int size, const int start)
{
	int visitedDepth[size];
	clearArray(visitedDepth, size);

	Stack *stack = init();
	push(stack, start);

	while (stack->size)
	{
		int cNode = pop(stack);

		if (!visitedDepth[cNode])
		{
			visitedDepth[cNode] = 1;

			printf("%d ", cNode);

			for (int i = (size - 1); i >= 0; --i)
				if (graphs[cNode][i])
					push(stack, i);
		}
	}

	freeStack(stack);
}

/*
 * Если граф неориентированный - то рёбра двунаправлены,
 * а значит, что полустепень захода == общему количеству рёбер у вершины
 *
 * Исходя из вышесказанного выходит, что при обходе матрицы смежности
 * необходимо посчитать у каждой вершины количество рёбер
 */
void adjacencyCount(int** matrix, const int size, bool isOriented)
{
	int countEdge[size];
	clearArray(countEdge, size);

	/*
	 * Использую стек для вывода смежных вершин
	 */
	Stack *stack = init();

	printf("\nВывод полустепеней захода для%sориентированного графа:\n", isOriented ? " " : " не");

	if (isOriented)
	{
		for (int y = size - 1; y >= 0; --y)
			for (int x = size - 1; x >= 0; --x)
				if (matrix[x][y])
				{
					countEdge[y]++;
					push(stack, y);
					push(stack, x);
				}

		for (int i = 0; i < size; ++i)
		{
			printf("Вершина #%d, рёбер: %d (", i + 1, countEdge[i]);
			for (int j = 0; j < countEdge[i]; ++j)
				printf("[%d <---- %d]", pop(stack) + 1, pop(stack) + 1);
			printf(")\n");
		}
	}
	else
	{
		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
				if (matrix[y][x])
				{
					if (y == x)
					{
						countEdge[y] += 2;
						push(stack, x);
						push(stack, y);
					}
					else
						countEdge[y]++;
					push(stack, x);
					push(stack, y);
				}

			printf("Вершина #%d, рёбер: %d (", y + 1, countEdge[y]);
			while (stack->size)
				printf("[%d <---> %d]", pop(stack) + 1, pop(stack) + 1);
			printf(")\n");
		}
	}

	freeStack(stack);
}

void traversalCount2(int **matrix, int start, const int size, int *visitedDepth)
{
	if (!visitedDepth)
	{
		visitedDepth = (int *)malloc(sizeof(int) * size);
		clearArray(visitedDepth, size);
	}

	printf("%d ", start);

	for (int i = 0; i < size; ++i)
	{
		if (matrix[i][start] && !visitedDepth[i])
		{
			visitedDepth[start]++;
			traversalCount2(matrix, i, size, visitedDepth);
		}
	}
}

void traversalCount(int **matrix, int start, const int size, int *visitedDepth)
{
	if (!visitedDepth)
	{
		visitedDepth = (int *)malloc(sizeof(int) * size);
		clearArray(visitedDepth, size);
	}

	if (visitedDepth[start])
		return;
	else
		visitedDepth[start]++;

	static int startVertex = -1;

	int count = 0;
	bool adjacentVertex = false;
	Stack *stack = init();

	if (startVertex == -1)
		startVertex = start;

	for (int i = 0; i < size; ++i)
	{
		if (matrix[start][i])
		{
			if (i != startVertex)
				push(stack, i);
			count++;
		}
	}

	if (!adjacentVertex)
		adjacentVertex = (startVertex == start || matrix[start][startVertex]);

	if (adjacentVertex)
	{
		printf("Вершина: %d => смежных вершин: %d\n", start, count);

		while (stack->size)
			traversalCount(matrix, pop(stack), size, visitedDepth);
	}

	freeStack(stack);

	if (startVertex == start)
	{
		free(visitedDepth);
		startVertex = -1;
	}
}
















