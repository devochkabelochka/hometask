#include <stdlib.h>
#include <stdio.h>

int g_level = 0;

void shannon (int start, int end, int arr[20], char code[20][20], int level) {
    int i = start;
    int j = end;
    int isum = arr[i], jsum = arr[j];

    if (level > g_level) {
        g_level = level;
    }
    while (i < (j - 1)) {
        while (isum > jsum && i < (j - 1)) {
            j--;
            jsum += arr[j];
        }
        while (isum < jsum && i < (j - 1)) {
            i++;
            isum += arr[i]; 
        }
    }

    if (i == start) {
        code[start][level] = '0';
    }
    else if ((i - start) >= 1) {
        for (int k = start; k <= i; ++k)
            code[k][level] = '0';

        shannon(start, i, arr, code, level + 1);
    }

    if (j == end) {
        code[end][level] = '1';
    }
    else if ((end - j) >= 1) {
        for (int k = j; k <= end; ++k)
            code[k][level] = '1';

        shannon(j, end, arr, code, level + 1);
    }
}

int main()
{
    int arr[20];
    int n, i, j;
    printf("Enter the number of symbols: ");
    scanf("%d ", &n);
    

    for (i = 0; i < n; ++i) {
        int s;
        printf("Enter symbol frequency: ");
        scanf("%d ", &s);
        j = i;
        while (j && arr[j - 1] < s) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = s;
    }

    char code[20][20];

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; j++) {
            code[i][j] = 'X';
        }
    }

    shannon(0, n - 1, arr, code, 0);

    printf("\n\n DATA CODE");
    for (i = 0; i < n; ++i) {
        printf("\n%4d: ", arr[i]);
        for (j = 0; j <= g_level; j++) {
            if (code[i][j] != 'X')
                printf("%c", code[i][j]);
        }
    }
    printf("\n");

    return 0;
}

