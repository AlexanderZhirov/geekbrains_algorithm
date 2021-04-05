#include "libhw.h"
#include <limits.h>
#include "liblist.h"

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

    tQueue *qT = initTQ();                      // очередь для вершин
    iQueue *qI = initIQ();                      // очередь для высоты текущей вершины
    addTN(qT, root);                            // добавление корня в очередь
    addIN(qI, 0);                               // добавление для корня высоты в очередь

    while (qT->size)                            // перебор ВСЕХ вершин
    {
        BinTreeIntNode *cNode = rmTN(qT);       // текущая вершина
        int height = rmIN(qI);                  // высота текущей вершины

        if (height > 1)                         // если высота больше единицы - дерево имеет дисбаланс
        {
            freeTQ(qT);                         // очистка очереди вершин
            freeIQ(qI);                         // очистка очереди высот вершин
            return false;
        }

        if (cNode->left && cNode->right)        // если у вершины в наличии обе ветви - высота == 0
        {
            addTN(qT, cNode->left);             // добавление левой ветви в очередь
            addIN(qI, height);                  // добавление для левой ветви высоты в очередь
            addTN(qT, cNode->right);            // добавление правой ветви в очередь
            addIN(qI, height);                  // добавление для правой ветви высоты в очередь
        }
        else if (cNode->left)                   // если у вершины в наличии левая ветвь - высота == +1
        {
            addTN(qT, cNode->left);             // добавление левой ветви в очередь
            addIN(qI, ++height);                // добавление для левой ветви высоты в очередь
        }
        else if (cNode->right)                  // если у вершины в наличии правая ветвь - высота == +1
        {
            addTN(qT, cNode->right);            // добавление правой ветви в очередь
            addIN(qI, ++height);                // добавление для правой ветви высоты в очередь
        }
    }

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
		while (elementCount > 0)
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
			elementCount--;
		}
	}
	freeTQ(queue);

	return NULL;
}
