#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*x,const void*y)
{
    return strcmp((const char*)y,(const char*)x);
}
int main()
{
    char a [5][100];
    int i;
    memset (a,0,sizeof(a));
    for(i = 0;i<5;i++)
    {
        scanf("%s",a[i]);
    }
    qsort(a,5,sizeof(*a),cmp);
    for(i=0 ; i<5 ; i++)
    {
        printf("%s\n",a[i]);
    }
    return 0;
}
