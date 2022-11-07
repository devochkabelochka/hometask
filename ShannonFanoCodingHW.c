#include <stdio.h>
#include <locale.h>


struct my
{
    char ch;
    int kol;
    float chast;
    char code[20];
};


int comparison (char *a, char *b)
{
    int i = 0;
    while ((a[i] !='\0') || (b[i] != '\0'))
    {
        if (a[i] != b[i])
        {
            return 0;
        }
        i ++;
    }
    return 1;
}


void AddChar(char *x, char y)
{
    int i = 0;
    while (x[i] != '\0') i++;
    x[i++] = y;
    x[i] = '\0';
}


void decToBin_rec(unsigned char a)
{
    char code[20];
    code[0]='\0';
    int num = (int)(a);
    while (num > 0) {
        int frag_i = num % 2;
        char frag = (char)(frag_i);
        AddChar(code, frag);
        num /= 2;
    }
    printf("%s\n", code);
}


void capybara(char *x, unsigned char y)
{
    for(unsigned char i = 0x80; i; i >>= 1)
    {
        char joke = y & i ? '1' : '0';
        if (joke == '1')
        {
            AddChar(x, joke);
        }
        else if (joke == '0')
        {
            AddChar(x, joke);
        }
    }
//    printf("%s\n", x);
}


unsigned char bitToChar(char *str)
{
    int dec_value = 0;
     
        // Initializing base value to 1, i.e 2^0
        int base = 1;
     
        int len = sizeof(str);
        for (int i = len - 1; i >= 0; i--) {
            if (str[i] == '1')
                dec_value += base;
            base = base * 2;
        }
//    printf("%c\n", dec_value);
    return (char)(dec_value);
}


void functiontest(char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        j += str[i] - 48;
        i ++;
    }
}


void archieve( char *str)
{
//    printf("asfsd %s\n", str);
    FILE *fp;
    fp = fopen("/Users/w6itec6apel/Desktop/politex_programming/for_alena/for_alena/archieve.txt", "w");
    fprintf(fp, "%s", str);
    fclose(fp);
}


void unarchieve(char *str)
{
    FILE *fp;
    fp = fopen("/Users/w6itec6apel/Desktop/politex_programming/for_alena/for_alena/archieve.txt", "r");
    if (fp == NULL)
    {
        printf("File not opened! Error!");
    }
    else{
        printf("File opened!\n");
    }
    unsigned char ch;
    
    char ok_i_pullup[20];
    ok_i_pullup[0]='\0';
    
    int count = 0;
    
    while (!feof(fp))
    {
        ch = fgetc(fp);
        if (ch != 255 && count % 2 == 0) {
//            printf("%c\n", ch);
            capybara(str, ch);
        }
        count ++;
    }
//    printf("%s\n", str);
}


void connection(char *str, char *stp)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i ++;
    }
    int j = 0;
    while (stp[j] != '\0')
    {
        str[i + j] = stp[j];
        j ++;
    }
    str[i + j] = '\0';
}


void fano(struct my*P, int first, int last)
{
    if (first == last) return;
    if (first + 1 == last)
    {
        AddChar(P[first].code, '0');
        AddChar(P[last].code, '1');
        return;
    }

    int numsum = 0;
    int n = 0;
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
            if (numsum == 0)
            {
                numsum = 1;
            }
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
    
    fano(P, numsum, last);
    fano(P, first, numsum-1);
}


int vs[256] = { 0 };
int N;
char str[30] = "qwerqwe";

int main()
{
    int count_capybara = 0;
    while (str[count_capybara] != 0)
    {
        vs[str[count_capybara]]++;
        count_capybara++;
    }
    for (int i = 0; i < 256; i++)
        if (vs[i] != 0)
        {
            N++;
        }
    struct my new_struct[N];
    int j = 0;
//    float i_new = i;
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
                int tmp = new_struct[j].kol;
                char tmp_ch = new_struct[j].ch;
                float tmp_chast = new_struct[j].chast;
                new_struct[j] = new_struct[j + 1];
                new_struct[j + 1].kol = tmp;
                new_struct[j + 1].ch = tmp_ch;
                new_struct[j + 1].chast = tmp_chast;
                flag = 0;
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
    printf("\n");
    fano(new_struct, 0, N - 1);
    
    for (int i = 0; i < N; i++)
    {
        printf("%c %s\n", (new_struct + i)->ch, (new_struct + i)->code);
    }
    printf("\n");
    
    char code_exit[100];
    
    for (int i = 0; i < sizeof(str); i ++) {
        for (int j = 0; j < N; j ++) {
            if ((new_struct + j) ->ch == str[i])
            {
                connection(code_exit, (new_struct + j) ->code);
            }
        }
    }
    
//    printf("raw code - %s\n\n", code_exit);
    
    int count = 0;
    for (int i = 0; i < sizeof(code_exit); i ++) {
        if (code_exit[i] == '1' || code_exit[i] == '0') {
            count ++;
        }
    }
//    printf("%d\n", count);
    if (count % 8 != 0 && count != 0)
    {
//        printf("yes");
        int count_i = 1;
        while (count_i % 8 != 0) {
            AddChar(code_exit, '0');
            count_i ++;
        }
    }
//    printf("%s\n", code_exit);
    
    char eight_bit[10];
    char code_final_final_exit[100];
    code_final_final_exit[0] = '\0';
    eight_bit[0] = '\0';
    int count_bebra = 0;
    
    for (int i = 0; i < sizeof(code_exit); i ++) {
        if (code_exit[i] == '1' || code_exit[i] == '0') {
//            printf("%c\n", code_exit[i]);
            if (i % 8 == 0 && i != 1 && i != 0) {
                printf("8-bit code - %s\n", eight_bit);
                functiontest(eight_bit);
                char code_final_local = bitToChar(eight_bit);
//                printf("dsfs %c\n", code_final_local);
                connection(code_final_final_exit, &code_final_local);
                count_bebra ++;
//                AddChar(code_final_final_exit, ' ');
//                char eight_bit[10];
                eight_bit[0] = '\0';
            }
            AddChar(eight_bit, code_exit[i]);
        }
    }
    code_final_final_exit[count_bebra+1] = '\0';
//    printf("%d\n", count_bebra);
    archieve(code_final_final_exit);
    
//---------------------------OPENING-------------------------------------------------------------
    
    printf("\n");
    char unstr[20];
    unstr[0] = '\0';
    
    unarchieve(unstr);
    printf("\n");
    printf("OUTPUT: %s\n", unstr);
//    printf("%lu\n", sizeof(unstr));
    
    char local_code[10];
    local_code[0] = '\0';
    
//    for (int i = 0; i < N; i ++) {
//        printf("%s\n", (new_struct + i) ->code);
//    }
    int count_dog = 0;
    char ultra_super_final_code[20];
    ultra_super_final_code[0] = '\0';
    
    for (int i = 0; i < sizeof(unstr); i ++) {
//        printf("%c", unstr[i]);
        AddChar(local_code, unstr[i]);
        
        for (int j = 0; j < N; j ++) {
            if ((comparison(local_code, (new_struct + j) ->code) == 1) && (count_dog < count_capybara) ) {
//                printf("%c", (new_struct + j) ->ch);
                AddChar(ultra_super_final_code, (new_struct + j) ->ch);
                count_dog ++;
                local_code[0] = '\0';
            }
        }
    }
    printf("\nOUTPUT WORD: %s\n", ultra_super_final_code);
    return 0;
}
