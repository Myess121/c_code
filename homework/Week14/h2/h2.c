#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b);
int main()
{
    char a[200],x;
    int i = 0,j;
    memset(a,0,sizeof(a));
    while((a[i] = getchar()) != '\n')
    {
        i++;
    }
    qsort(a,i,sizeof(char),cmp);
    if(a[0] == '0'){
        printf("0\n");
        return 0;
    }
    for(j = 0;j<i;j++)
    {
        printf("%c",a[j]);
    }
    printf("\n");
    return 0;

}

int cmp(const void *a,const void *b)
{
    return *(char*)b - *(char*)a;
}