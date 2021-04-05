#ifndef LIBLIST_H_
#define LIBLIST_H_

#include <stdbool.h>
#include "libtree.h"

typedef struct tNode
{
    BinTreeIntNode *dat;
    struct tNode *next;
} tNode;

typedef struct
{
    tNode *head;
    int size;
} tQueue;

typedef struct iNode
{
    int dat;
    struct iNode *next;
} iNode;

typedef struct
{
    iNode *head;
    int size;
} iQueue;

tQueue *initTQ();
void addTN(tQueue *, BinTreeIntNode *);
BinTreeIntNode *rmTN(tQueue *);
void freeTQ(tQueue *);

iQueue *initIQ();
void addIN(iQueue *, int);
int rmIN(iQueue *);
void freeIQ(iQueue *);

#endif
