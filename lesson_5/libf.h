#ifndef LIBF_H_
#define LIBF_H_

// Домашнее задание 1.
void improvedQuickSort(int *, int, int);
int *median(int *, int *, int *);
// Домашнее задание 2.
void evenBucketSort(int *, int);

// Вспомогательные функции
void swap(int *, int *);
void fillRandom(int *, const int, const int);
void printArray(int *array, const int size, const int offset);

#endif
