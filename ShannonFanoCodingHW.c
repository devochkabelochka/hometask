#include "stdafx.h" //<stdio.h>

int array[20];


struct my
{
	char ch;
	int kol;
	float chast;
};


void fano(my*P , int first, int last )
{
	// когда выйтти
	// где середина  nser

	for (int i = first; i < nser; i++)
	{
		//add '0'
	}
	for (int i = nser; i <= last; i++)
	{
		//add '1'
	}
	fano(P, first, nser - 1);
	fano(P, nser, last);
}

int bubble(int arr[20], int )
{
	return 0;
}




int vs[256] = { 0 };
int N;
char str[20] = "baraban";


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

		if (vs[i] != 0)
		{
			new_struct[j].ch = i;
			new_struct[j].kol = vs[i]; 
			new_struct[j].chast = vs[i] / i_new;
			j++;
		}

	for (int i = 0; i < N; i++)
	{
		printf("%c  %d  %f\n", new_struct[i].ch, new_struct[i].kol, new_struct[i].chast);
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
