#include<stdio.h>
#include <ctype.h>


int asciiValueToBinary(int asciiInput)//получаем из БУКВЫ 8-ми битный КОД
{
    int res = 0, i = 1, rem;

    while (asciiInput > 0)
    {
        rem = asciiInput % 2;
        res += (i * rem);
        asciiInput /= 2;
        i *= 10;
    }
    return(res);
}

int main()
{
    char *string = "BARABAN";//Начальное слово
    char codeOfWord[sizeof(string) * 8];//Выходное слово
    
    int avbReturn = 0;//восьмибитное представление каждой буквы
    int len = 0;

    for (int i = 0; i < sizeof(string)-1; i++) {

        if (string[i]) {
            
            char codeOfWord_local[10];//Объявление оперативной переменной для записи из int в char

            avbReturn = asciiValueToBinary(toascii(string[i]));//собственно это и есть восьмибитное представление буквы

            sprintf(codeOfWord_local, "%d", avbReturn);//Замена типа данных
            snprintf(codeOfWord, sizeof codeOfWord, "%s%s", codeOfWord, codeOfWord_local);//Сложение восьмибитных представление слов в одно большое слово

            len += sprintf(codeOfWord_local, "%d", avbReturn) + 1;//Сумма букв
            printf("%c - %s\n", string[i], codeOfWord_local);//Выврд
        }
    }
    printf("\n<<==================OUTPUT=WORD==================>>\n\n%s\n", codeOfWord);
//sajjfaskdjfkajskdfjakldjfkajksdjksad
    return 0;
}
