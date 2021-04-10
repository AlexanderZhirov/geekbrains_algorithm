#include "libhw.h"
#include <stdlib.h>

char *caesar(char *in, int key, bool encrypt)
{
	int step = encrypt ? key : -key;
	char *ptr = in;
	int size = 0;

	while (*(ptr++) != '\0')
			size++;

	char *string = (char *)malloc(sizeof(char) * (size + 1));
	ptr = in;
	size = 0;

	while (*(ptr++) != '\0')
	{
		string[size] = in[size] + step;
		size++;
	}

	return string;
}

char *caesar2(char *in, int key, bool encrypt)
{
	int step = encrypt ? key : -key;
	char *ptr = in;
	int size = 0;
	const int alphabetSize = 26;

	while (*(ptr++) != '\0')
		size++;

	char *string = (char *)malloc(sizeof(char) * (size + 1));
	ptr = in;
	size = 0;
	int ch;

	while (*(ptr++) != '\0')
	{
		ch = in[size];

		if (ch >= 'A' && ch <= 'Z')
		{
			ch += (step % alphabetSize);
			if (ch < 'A')
				ch = 'Z' - ('A' - ch) + 1;
			if (ch > 'Z')
				ch = 'A' + (ch - 'Z') - 1;
		}

		if (ch >= 'a' && ch <= 'z')
		{
			ch += (step % alphabetSize);
			if (ch < 'a')
				ch = 'z' - ('a' - ch) + 1;
			if (ch > 'z')
				ch = 'a' + (ch - 'z') - 1;
		}

		string[size++] = ch;
	}

	return string;
}

char *shuffle(char *in, char *key, bool encrypt)
{
	char *ptrKey = key;                                           // указатель на ключ
	int sizeKey = 0;                                              // размер ключа
	char *ptrIn = in;                                             // указатель на исходную строку
	int sizeIn = 0;                                               // размер исходной строки

	while (*(ptrKey++) != '\0')                                   // подсчет количества символов в ключе
		sizeKey++;

	while (*(ptrIn++) != '\0')                                    // подсчет количества символов в исходной строке
		sizeIn++;

	if (sizeKey > sizeIn)                                         // вернуть NULL если ключ больше шифруемого текста
		return NULL;

	int *posizions = (int *)malloc(sizeof(int) * (sizeKey + 1));  // выделение места для массива с нумераций символов ключа
	char *string = (char *)malloc(sizeof(char) * (sizeIn + 1));   // выделение места для измененного текста

	for (int i = 0; i < sizeKey; ++i)
	{
		int index = 0;                                            // нумерация текущего символа ключа
		char ch = key[i];                                         // текущий символ ключа

		for (int j = 0; j < sizeKey; ++j)                         // перебор символов ключа
			if (ch > key[j])
				index++;                                          // подсчет номера символа ключа
			else if (ch == key[j] && j < i)                       // при подсчете учитывать возможность совпадения одинаковых символов
				index++;                                          // подсчет номера символа ключа

		posizions[i] = index;                                     // внесение нового индекса
	}

	for (int i = 0; i < sizeIn; i += sizeKey)                     // конвертация текста согласно нового порядка символов
		for (int j = 0; j < sizeKey; ++j)
			if (i + sizeKey < sizeIn)
			{
				if (encrypt)                                      // для шифрования
					string[i + j] = in[i + posizions[j]];
				else                                              // для дешифрования
					string[i + posizions[j]] = in[i + j];
			}
			else                                                  // если размер ключа превышает оставшийся текст - оставить текст без изменений
				string[i + j] = in[i + j];

	free(posizions);                                              // освобождение массива с нумераций символов ключа

	return string;
}
