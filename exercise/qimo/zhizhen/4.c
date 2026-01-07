#include <stdio.h>
void delchar(char *str,char c);
int main ()
{
    int repeat;
    char s[100],c,*str;
    scanf("%d",&repeat);
    getchar();
    while(repeat > 0)
    {
        str = s;
        while((c = getchar()) != '\n')
        {
            *str = c;
            str ++;
        }
        *str = 0;
        str = s;
        scanf("%c",&c);
        getchar();
        delchar(str,c);
        printf("result: %s\n",s);
        repeat --;
    }

    return 0;
}
void delchar(char *str,char c)
{
    char * s;
    s = str ;
    while(*str)
    {
        if(c == *str){
            str ++;
            continue;
        }
        *s = *str;
        s ++;
        str ++;
    }
    *s = 0;
}