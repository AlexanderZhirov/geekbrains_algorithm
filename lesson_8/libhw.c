#include "libhw.h"
#include <limits.h>
#include "liblist.h"

#define ABS(x) (((x) < 0) ? -(x) : (x))

/*
 * Во избежании переполнения стека при рекурсивном вызове
 * итеративная функция будет параллельно проверять ВСЕ ветви спускаясь
 * от корня к листьям. В случае нахождения ПЕРВОГО дисбаланса функция
 * вернёт false, и не нужно продолжать далее проверку на баланс.
 * В отличии от рекурсивной функции данная функция может практично
 * работать с деревьями имеющих очень большую высоту.
 *
 * Из-за отсутствия очередей в Си - пришлось дублировать код очередей
 * для каждого типа:
 * tQueue *qT = initTQ() - создание очереди queueTree для вершин (BinTreeIntNode *)
 * iQueue *qI = initIQ() - создание очереди queueInt для высот (int)
 */
bool isBalanced(BinTreeIntNode *root)
{
    if (root == NULL)
        return true;

    int level = 1;                                                // текущий уровень ветви
    int minLevel = 0;                                             // минимальный уровень ветви
    int maxLevel = 0;                                             // максимальнй уровень ветви
    int count = 0;                                                // количество итераций на текущем уровне

    tQueue *qT = initTQ();                                        // очередь для вершин
    iQueue *qI = initIQ();                                        // очередь для высоты текущей вершины
    addTN(qT, root);                                              // добавление корня в очередь
    addIN(qI, 0);                                                 // добавление для корня высоты в очередь

    while (qT->size)                                              // перебор ВСЕХ вершин
    {
    	count = qT->size;                                         // перебор текущего уровня вершин
    	while (count--)
    	{
			BinTreeIntNode *cNode = rmTN(qT);                     // текущая вершина
			int height = rmIN(qI);                                // высота текущей вершины

			if (height > 1 || ABS(minLevel - maxLevel) > 1)       // проверка дерева на дисбаланс
			{
				freeTQ(qT);                                       // очистка очереди вершин
				freeIQ(qI);                                       // очистка очереди высот вершин
				return false;
			}

			if (cNode->left && cNode->right)                      // если у вершины в наличии обе ветви - высота == 0
			{
				addTN(qT, cNode->left);                           // добавление левой ветви в очередь
				addIN(qI, height);                                // добавление для левой ветви высоты в очередь
				addTN(qT, cNode->right);                          // добавление правой ветви в очередь
				addIN(qI, height);                                // добавление для правой ветви высоты в очередь
			}
			else if (cNode->left)                                 // если у вершины в наличии левая ветвь - высота == +1
			{
				addTN(qT, cNode->left);                           // добавление левой ветви в очередь
				addIN(qI, ++height);                              // добавление для левой ветви высоты в очередь
				minLevel++;
			}
			else if (cNode->right)                                // если у вершины в наличии правая ветвь - высота == +1
			{
				addTN(qT, cNode->right);                          // добавление правой ветви в очередь
				addIN(qI, ++height);                              // добавление для правой ветви высоты в очередь
				minLevel++;
			}
			else
			{
				if (ABS(level - minLevel) == 1)                   // установка минимального уровня ветви
					minLevel = level;
				if (maxLevel < level)                             // установка максимального уровня ветви
					maxLevel = level;
			}
    	}
    	level++;                                                  // увеличение текущего уровня
    }

    freeTQ(qT);
    freeIQ(qI);

    return true;
}

BinTreeIntNode* searchNode(BinTreeIntNode *root, int data)
{
	if (root == NULL)
		return NULL;

	if (root->key > data)
		return searchNode(root->left, data);
	else if (root->key < data)
		return searchNode(root->right, data);
	else
		return root;
}

BinTreeIntNode* searchNode2(BinTreeIntNode *root, int data)
{
	if (root == NULL)
		return NULL;

	tQueue *queue = initTQ();
	addTN(queue, root);

	while (queue->size)
	{
		int elementCount = queue->size;
		while (elementCount--)
		{
			BinTreeIntNode *node = rmTN(queue);

			if (node->key == data)
			{
				freeTQ(queue);
				return node;
			}
			else
			{
				if (node->left != NULL)
					addTN(queue, node->left);
				if (node->right != NULL)
					addTN(queue, node->right);
			}
		}
	}
	freeTQ(queue);

	return NULL;
}
