#include <stdio.h>

int is_prime(const unsigned int);

int main(const int argc, const char **argv)
{
	unsigned int num;
	printf("Введите целое положительно число: ");
	scanf("%d", &num);
	printf("Число %d %sпростое\n", num, (is_prime(num) ? "" : "не "));

	return 0;
}

int is_prime(const unsigned int num)
{
	if (num > 3)
	{
		unsigned int limit = num / 2;

		for (unsigned int i = 2; i <= limit; ++i)
		{
			if (num % i == 0)
				return 0;
		}
	}

	return 1;
}
