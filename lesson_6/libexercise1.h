#ifndef LIBEXERCISE1_H_
#define LIBEXERCISE1_H_

#include <stdbool.h>
#include <stdio.h>

#define SIZE 1000
extern int Stack[SIZE];
extern int cursor;

bool PushStack(int);
int PopStack();

#endif
