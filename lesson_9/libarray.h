#ifndef LIBARRAY_H_
#define LIBARRAY_H_

int get2dInt(int **, const int, const int);
void set2dInt(int **, const int, const int, int);
int **init2dIntArray(const int, const int);
void print2dIntArray(int **, const int, const int, int);
void free2dIntArray(int **, const int, const int);
void printIntArray(int *, int, int);
void clearIntArray(int *, const int);

#endif
