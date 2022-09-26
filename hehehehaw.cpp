#include <stdio.h>

int main()
{
    FILE * hi;
    char n;
    hi = fopen("/home/lokobelka/Desktop/projects/test.txt","rb+");
    while(!feof(hi))
    {
        int res = fscanf(hi,"%c",&n);
        if (res == EOF)
        {
            break;
        }
    printf("%c \n",n);
    }
    fclose(hi);
    return(0);
}