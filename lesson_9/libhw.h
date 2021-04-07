#ifndef LIBHW_H_
#define LIBHW_H_

#include <stdbool.h>

void clearArray(int *, int);
void depthFirstTraverse(int **, int, const int);
void adjacencyCount(int **, const int, bool);
void traversalCount(int **, int, const int, int *);

#endif
