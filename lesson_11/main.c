#include <stdio.h>
#include <stdlib.h>
#include "libhw.h"

void exercise_1();
void exercise_2();

int main(const int argc, const char **argv)
{
	exercise_1();
	exercise_2();

	return 0;
}

void exercise_1()
{
	char string[] = "A C program is like a fast dance on a newly waxed dance floor by people carrying razors.";
	char *encrypted, *decrypted;
	const int step = 15;

	printf("Шифрование с использованием кодировки\n");
	printf("Исходный текст: %s\n", string);
	encrypted = caesar(string, step, true);
	printf("Зашифрованный текст: %s\n", encrypted);
	decrypted = caesar(encrypted, step, false);
	printf("Расшифрованный текст: %s\n", decrypted);

	free(encrypted);
	free(decrypted);

	printf("\nШифрование с использованием алфавита:\n");
	printf("Исходный текст: %s\n", string);
	encrypted = caesar2(string, step, true);
	printf("Зашифрованный текст: %s\n", encrypted);
	decrypted = caesar2(encrypted, step, false);
	printf("Расшифрованный текст: %s\n", decrypted);

	free(encrypted);
	free(decrypted);
}

void exercise_2()
{
	char string[] = "A C program is like a fast dance on a newly waxed dance floor by people carrying razors.";
	char key[] = "ENCRYPT";
	char *encrypted, *decrypted;

	printf("Шифрование и расшифровка перестановками:\n");
	printf("Исходный текст: %s\n", string);
	encrypted = shuffle(string, key, true);
	printf("Зашифрованный текст: %s\n", encrypted);
	decrypted = shuffle(encrypted, key, false);
	printf("Расшифрованный текст: %s\n", decrypted);

	free(encrypted);
	free(decrypted);
}
