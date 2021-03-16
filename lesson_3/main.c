#include <stdio.h>
#include <stdlib.h>

#define WIDTH 7
#define HEIGHT 7

int board[WIDTH][HEIGHT] =
{
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0},
};

void exercise_1(unsigned int);
float exercise_2(int, int);
float exercise_3(int, int);
float exercise_4(int, int);
void exercise_5();

int routes(int, int);

int main(const int argc, const char **argv)
{
	exercise_1(128);
	printf("\n%f", exercise_2(4, -2));
	printf("\n%f", exercise_3(4, -2));
	printf("\n%f", exercise_4(4, -2));
	printf("\n");
	exercise_5();

	return 0;
}

void exercise_1(unsigned int n)
{
	if (n < 2)
		printf("%d", n);
	else
	{
		exercise_1(n / 2);
		printf("%d", n % 2);
	}
}

float exercise_2(int a, int n)
{
	if (n != 0)
	{
		int b = a;
		for (int i = 1; i < abs(n); ++i)
			b *= a;
		return (n > 0) ? b : (1.0 / b);
	}
	else
		return 1.0;
}

float exercise_3(int a, int n)
{
	if (n < 0)
	{
		return (1.0 / exercise_3(a, -n));
	}
	else if (n > 0)
	{
		int b = a;
		while (--n)
			b *= a;
		return b;
	}
	else
		return 1.0;
}

float exercise_4(int a, int n)
{
	if (n < 0)
		return (1.0 / exercise_4(a, -n));
	else if (n > 0)
	{
		if (n % 2 == 1)
			return exercise_4(a, n - 1) * a;
		else {
			float c = exercise_4(a, n / 2);
			return c * c;
		}
	}
	else
		return 1.0;
}

void exercise_5()
{
	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
			printf("%5d", routes(x, y));
		printf("\n");
	}
}

int routes(int x, int y)
{
	if (board[y][x] == 0)
	{
		if (x == 0 && y == 0)
			return 0;
		else if (x == 0 && y - 1 == 0)
			return 1;
		else if (y == 0 && x - 1 == 0)
			return 1;
		else
			return routes(x, y - 1) + routes(x - 1, y);
	}
	else
		return 0;
}

