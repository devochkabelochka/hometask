// ConsoleApplication166.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <time.h>
#include <windows.h>


struct my
{
	char ch;
	int kol;
};


int numbers[300] = { 0 };
int N;
char str[20] = "baraban";

int main()
{
	int i = 0;

	while (str[i] != 0)
	{
		numbers[str[i]]++;
		i++;
	}

	for (int i = 0; i < 256; i++)
	{
		if (numbers[i] != 0)
		{
			printf("%c %d \n", i, numbers[i]);
			N++;
		}
		my * ptr = new my[N];
		if (ptr == NULL)
		{
			printf("error");
		}

		int j = 0;

		for (int i = 0; i < 256; i++)
		{
			if (numbers[i] != 0)
			{
				ptr[j].ch = i;
				ptr[j].kol = numbers[i];
			}
		}

		for (int i = 0; i < N/sizeof(str); i++)
		{
			printf("%c %d\n", ptr[i].ch, ptr[i].kol);
		}
	}
    return 0;
}


