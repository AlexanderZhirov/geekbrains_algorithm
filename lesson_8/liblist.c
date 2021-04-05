#include "liblist.h"
#include <stdlib.h>
#include <stdio.h>

tQueue *initTQ()
{
    tQueue *queue = (tQueue *)malloc(sizeof(tQueue));
    queue->head = NULL;
    queue->size = 0;
    return queue;
}

void addTN(tQueue *queue, BinTreeIntNode *data)
{
    tNode *new = (tNode *)malloc(sizeof(tNode));
    new->dat = data;
    new->next = NULL;

    tNode *current = queue->head;
    if (current == NULL)
    {
        queue->head = new;
        queue->size++;
        return;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
        queue->size++;
    }
}

BinTreeIntNode *rmTN(tQueue *queue)
{
    if (queue->head == NULL)
        return NULL;

    BinTreeIntNode *dat = queue->head->dat;
    tNode *current = queue->head;
    queue->head = current->next;
    queue->size--;

    free(current);

    return dat;
}

void freeTQ(tQueue *queue)
{
    while (queue->size)
        rmTN(queue);
    free(queue);
}

iQueue *initIQ()
{
    iQueue *queue = (iQueue *)malloc(sizeof(iQueue));
    queue->head = NULL;
    queue->size = 0;
    return queue;
}

void addIN(iQueue *queue, int data)
{
    iNode *new = (iNode *)malloc(sizeof(iNode));
    new->dat = data;
    new->next = NULL;

    iNode *current = queue->head;
    if (current == NULL)
    {
        queue->head = new;
        queue->size++;
        return;
    }
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
        queue->size++;
    }
}

int rmIN(iQueue *queue)
{
    if (queue->head == NULL)
        return -1;

    int dat = queue->head->dat;
    iNode *current = queue->head;
    queue->head = current->next;
    queue->size--;

    free(current);

    return dat;
}

void freeIQ(iQueue *queue)
{
    while (queue->size)
        rmIN(queue);
    free(queue);
}
