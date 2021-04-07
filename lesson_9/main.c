#include <stdio.h>
#include "libarray.h"
#include "libhw.h"

void exrcise_1();
void exrcise_2_1();
void exrcise_2_2();

int main(const int argc, const char **argv)
{
	exrcise_1();
	exrcise_2_1();
	exrcise_2_2();

	return 0;
}

void exrcise_1()
{
	const int SZ = 6;
	int **adjacency = init2dIntArray(SZ, SZ);

	set2dInt(adjacency, 0, 1, 1);
	set2dInt(adjacency, 0, 2, 1);
	set2dInt(adjacency, 1, 3, 1);
	set2dInt(adjacency, 1, 4, 1);
	set2dInt(adjacency, 1, 5, 1);
	set2dInt(adjacency, 2, 5, 1);
	set2dInt(adjacency, 3, 0, 1);
	set2dInt(adjacency, 5, 4, 1);

	printf("Обход в глубину с использованием стека:\n");
	depthFirstTraverse(adjacency, SZ, 0);
	printf("\n");
	depthFirstTraverse(adjacency, SZ, 2);
	printf("\n");
	depthFirstTraverse(adjacency, SZ, 1);
	printf("\n");
	adjacencyCount(adjacency, SZ, true);
}

void exrcise_2_1()
{
	const int SZ = 14;
	int **adjacency = init2dIntArray(SZ, SZ);

	set2dInt(adjacency, 0, 1, 1);
	set2dInt(adjacency, 0, 6, 1);
	set2dInt(adjacency, 0, 7, 1);

	set2dInt(adjacency, 1, 0, 1);
	set2dInt(adjacency, 1, 2, 1);
	set2dInt(adjacency, 1, 6, 1);
	set2dInt(adjacency, 1, 10, 1);

	set2dInt(adjacency, 2, 1, 1);
	set2dInt(adjacency, 2, 2, 1);
	set2dInt(adjacency, 2, 3, 1);

	set2dInt(adjacency, 3, 2, 1);
	set2dInt(adjacency, 3, 9, 1);
	set2dInt(adjacency, 3, 13, 1);

	set2dInt(adjacency, 4, 8, 1);

	set2dInt(adjacency, 6, 0, 1);
	set2dInt(adjacency, 6, 1, 1);
	set2dInt(adjacency, 6, 10, 1);
	set2dInt(adjacency, 6, 11, 1);

	set2dInt(adjacency, 7, 0, 1);
	set2dInt(adjacency, 7, 11, 1);

	set2dInt(adjacency, 8, 4, 1);
	set2dInt(adjacency, 8, 8, 1);

	set2dInt(adjacency, 9, 3, 1);
	set2dInt(adjacency, 9, 9, 1);

	set2dInt(adjacency, 10, 1, 1);
	set2dInt(adjacency, 10, 6, 1);
	set2dInt(adjacency, 10, 11, 1);
	set2dInt(adjacency, 10, 12, 1);

	set2dInt(adjacency, 11, 6, 1);
	set2dInt(adjacency, 11, 7, 1);
	set2dInt(adjacency, 11, 10, 1);
	set2dInt(adjacency, 11, 12, 1);

	set2dInt(adjacency, 12, 10, 1);
	set2dInt(adjacency, 12, 11, 1);
	set2dInt(adjacency, 12, 13, 1);

	set2dInt(adjacency, 13, 3, 1);
	set2dInt(adjacency, 13, 12, 1);

	adjacencyCount(adjacency, SZ, false);
}

void exrcise_2_2()
{
	const int SZ = 6;
	int **adjacency = init2dIntArray(SZ, SZ);

	set2dInt(adjacency, 0, 1, 1);
	set2dInt(adjacency, 0, 2, 1);
	set2dInt(adjacency, 0, 3, 1);

	set2dInt(adjacency, 1, 0, 1);
	set2dInt(adjacency, 1, 3, 1);
	set2dInt(adjacency, 1, 4, 1);
	set2dInt(adjacency, 1, 5, 1);

	set2dInt(adjacency, 2, 0, 1);
	set2dInt(adjacency, 2, 5, 1);

	set2dInt(adjacency, 3, 0, 1);
	set2dInt(adjacency, 3, 1, 1);

	set2dInt(adjacency, 4, 1, 1);
	set2dInt(adjacency, 4, 5, 1);

	set2dInt(adjacency, 5, 1, 1);
	set2dInt(adjacency, 5, 2, 1);
	set2dInt(adjacency, 5, 4, 1);

	printf("\nПодсчёт смежных вершин со стартовой вершины 5:\n");
	traversalCount(adjacency, 5, SZ, NULL);
	printf("\nПодсчёт смежных вершин со стартовой вершины 0:\n");
	traversalCount(adjacency, 0, SZ, NULL);
	printf("\nПодсчёт смежных вершин со стартовой вершины 1:\n");
	traversalCount(adjacency, 1, SZ, NULL);
}
