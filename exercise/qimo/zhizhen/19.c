#include <stdio.h>

char a[1000];
int main ()
{
    char *str;
    int c;
    str = a;
    while((c = getchar()) != '\n')
    {
        *str = (char)c;
        str ++;
    }
    while((c = getchar()) != EOF)//题目纯傻逼
    {
        *str = (char)c;
        str ++;
    }
    *str = 0;

    printf("%s\n",a);

    return 0;
}