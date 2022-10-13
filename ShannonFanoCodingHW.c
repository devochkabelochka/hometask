#include "stdafx.h"

int array[20];


struct my
{
	char ch;
	int kol;
	float chast;
	char code[20];
};

void AddChar(char *x, char y)
{
	int i = 0;
	while (x[i] != '\0') i++;
	x[i++] = y;
	x[i] = '\0';
}

void fano(my*P , int first, int last)
{
	if (first == last) return;
	if (first + 1 == last)
	{
		AddChar(P[first].code, '0');
		AddChar(P[last].code, '1');
		return;
	}

	int numsum, n = 0;
	float sumchast = 0;

	for (int i = first; i <= last; i++)
	{
		n += P[i].kol;
	}
	for (int i = first; i <= last; i++)
	{
		P[i].chast = P[i].kol / (n * 1.);
	}
	for (int i = first; i <= last; i++)
	{
		sumchast += P[i].chast;
		if (sumchast > 0.5)
		{
			numsum = i;
			break;
		}
	}

	
	for (int i = first; i < numsum; i++)
	{
		AddChar(P[i].code, '0');
	}
	for (int i = numsum; i <= last; i++)
	{
		AddChar(P[i].code, '1');
	}

	/*fano(P, first, numsum - 1);
	fano(P, numsum, last);*/

}

int vs[256] = { 0 };
int N;
char str[20] = "brbn";

int main()
{
	int i = 0;

	while (str[i] != 0)
	{
		vs[str[i]]++;
		i++;
	}

	for (int i = 0; i < 256; i++)
		if (vs[i] != 0)
		{
			N++;
		}																													

	my * new_struct = new my[N];

	int j = 0;
	float i_new = i;

	for (int i = 0; i < 256; i++)
	{
		if (vs[i] != 0)
		{
			new_struct[j].ch = i;
			new_struct[j].kol = vs[i];
		 
			j++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		(new_struct + i)->code[0] = '\0';
	}
	for (int i = 0; i < N - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < N - i - 1; j++)
		{
			if (new_struct[j].kol < new_struct[j + 1].kol)
			{
				my tmp = new_struct[j];
				new_struct[j] = new_struct[j + 1];
				new_struct[j + 1];
			/*	int tmp = new_struct[j].kol;
				char tmp_ch = new_struct[j].ch;
				float tmp_chast = new_struct[j].chast;
				new_struct[j].kol = new_struct[j + 1].kol;
				new_struct[j].ch = new_struct[j + 1].ch;
				new_struct[j].chast = new_struct[j + 1].chast;
				new_struct[j + 1].kol = tmp;
				new_struct[j + 1].ch = tmp_ch;
				new_struct[j + 1].chast = tmp_chast;
				flag = 0;*/
			}
		}
		if (flag)
		{
			break;
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%c %d %s\n", (new_struct + i)->ch, (new_struct + i)->kol, (new_struct + i)->code);
	}

	fano(new_struct, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%c  %s\n", (new_struct + i) -> ch, (new_struct + i) -> code);
	}

	return 0;
}



/*
void arr_sort(int* ptr, int arrLen)
{
	int i, j;
	for (i = 0; i < arrLen - 1; i++)
	{
		for (j = 0; j < arrLen - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < arrLen; i++)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
}


void main()
{
	int arr[] = { 1231241, 1232, 33, 5, 213, 532 };
	int len = sizeof(arr)/sizeof(len);

	arr_sort(arr, len);
}
*/
