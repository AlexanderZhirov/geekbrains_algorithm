#include "libhw.h"
#include <stdio.h>
#include <stdlib.h>

int simpleHashSum(char *in)
{
	char *ptrStr = in;
	int sumHash = 0;

	while (*ptrStr != '\0')
	{
		sumHash += (int)*ptrStr;
		ptrStr++;
	}

	return sumHash;
}

int *exchange(int *money, int size, int sum)
{
	if (!money)
		return NULL;

	int balance = 0;
	int *countMoney = (int *)malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		countMoney[i] = 0;

	for (int i = 0; i < size; ++i)
	{
		balance = sum / money[i];
		if (balance > 0)
			countMoney[i] = balance;
		sum %= money[i];
	}

	return countMoney;
}
