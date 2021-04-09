#include <stdio.h>
#include "libhw.h"

void exrcise_1();
void exrcise_2();

int main(const int argc, const char **argv)
{
	exrcise_1();
	exrcise_2();

	return 0;
}

void exrcise_1()
{
	char string[] = "Hello, world!";
	printf("%d\n", simpleHashSum(string));
}

void exrcise_2()
{
	int sum = 100;
	const int size = 5;
	int money[] = {50, 10, 5, 2, 1};

	int *countMoney = exchange(money, size, sum);

	for (int i = 0; i < size; ++i)
		printf("Номинал: %d, количество: %d\n", money[i], countMoney[i]);

	free(countMoney);
}
