#include <stdio.h>

int main()
{
    int a[10];
    int i,flag;
    for(i = 0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    flag = a[0];
    for(i = 1;i<10;i++)
    {
        if(flag<a[i]){
            flag = a[i];
        }
    }
    for(i = 0;i<10;i++)
    {
        if(a[i] == flag)
        {
            printf("%d\n",i+1);
        }
    }
    return 0;
}