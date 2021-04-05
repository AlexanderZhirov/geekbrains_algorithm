#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"
#include "libhw.h"
#include <time.h>

void exercise_1();
void exercise_2_3();

int main(const int argc, const char **argv)
{
	exercise_1();
	exercise_2_3();

	return 0;
}

void exercise_1()
{
	BinTreeIntNode *tree = treeInsert(NULL, 10);
	treeInsert(tree, 8);
	treeInsert(tree, 19);
	treeInsert(tree, 5);
	treeInsert(tree, 9);
	treeInsert(tree, 16);
	treeInsert(tree, 21);
	printf("Дерево%sсбалансировано: ", isBalanced(tree) ? " " : " не ");
	printBinTree(tree);
	treeInsert(tree, 26);
	treeInsert(tree, 25);
	printf("\nДерево%sсбалансировано: ", isBalanced(tree) ? " " : " не ");
	printBinTree(tree);
	freeBinTree(tree);
	printf("\n");
}

void exercise_2_3()
{
	srand(time(NULL));

	const int sizeSearch = 10;            // Размер массива значений для поиска в деревьях
	int forSearch[sizeSearch];            // Массив значений для поиска в деревьях

	const int size = 10;                  // Размер массива деревьев
	const int border = 100;               // Граница рандомных чисел
	const int nodes = 20;                 // Количество узлов в дереве

	int countBalance = 0;                 // Счётчик сбалансированных деревьев

	/*
	 * Заполнение массива для поиска в деревьях случайными значениями
	 */
	for (int i = 0; i < sizeSearch; ++i)
		forSearch[i] = (rand() % border);
	/*
	 * Создание динамического массива с деревьями
	 * Заполнение каждого дерева случайными значениями
	 */
	BinTreeIntNode **treeArray = (BinTreeIntNode **)malloc(sizeof(BinTreeIntNode *) * size);
	for (int i = 0; i < size; ++i)
	{
		treeArray[i] = treeInsert(NULL, rand() % border);
		for (int j = 0; j < nodes; ++j)
			treeInsert(treeArray[i], rand() % border);
	}
	/*
	 * Перебор деревьев
	 */
	for (int i = 0; i < size; ++i)
	{
		/*
		 * Проверка дерева на сбалансированность
		 */
		if(isBalanced(treeArray[i]))
		{
			countBalance++;
			printf("\n#%2d дерево сбалансировано: ", i + 1);
		}
		else
			printf("\n#%2d дерево не сбалансировано: ", i + 1);

		printBinTree(treeArray[i]);
		/*
		 * Поиск элементов из массива в текущем дереве
		 */
		for (int j = 0; j < sizeSearch; ++j)
		{
			/*
			 * searchNode()  - рекурсивная функция поиска элементов в дереве
			 * searchNode2() - функция для поиска элементов в дереве с использованием связного списка
			 */
//			BinTreeIntNode *current = searchNode(treeArray[i], forSearch[j]);
			BinTreeIntNode *current = searchNode2(treeArray[i], forSearch[j]);
			if (current)
				printf("\n%2d найдено в дереве", current->key);
			else
				printf("\n%2d не найдено в дереве", forSearch[j]);
		}

		printf("\n");
		freeBinTree(treeArray[i]);
	}

	free(treeArray);
	/*
	 * Подсчёт процента сбалансированных деревьев
	 */
	printf("\nКоличество сбалансированных деревьев: %.2f%%", ((float)countBalance * 100 / size));
}
