#include <stdio.h>  
#include <string.h>

int main ()
{
    int i = 0,n;
    char a[110],b[20],c[20],*p;
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    memset(b,0,sizeof(b));
    while ((a[i] = getchar())!='\n')
    {
        i++;
    }
    a[i] = '\0'; 
    i = 0;
    while ((b[i] = getchar())!='\n')
    {
        i++;
    }
    b[i] = '\0';
    i = 0;
    while ((c[i] = getchar())!='\n')
    {
        i++;
    }
    c[i] = '\0';
    n = strlen(b);
    i = 0;
    while((p = strstr(a+i,b)) != NULL)
    {
        for(;&a[i] != p;i++)
            {
                printf("%c",a[i]);
            }
        printf("%s",c);
        i = i + n ;
    }
    printf("%s\n",a+i);
    return 0;
}