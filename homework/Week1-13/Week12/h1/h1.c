#include <stdio.h>
int fun(int a,int b);
int main()
{
    int m,n,mnt;
    scanf("%d %d",&m,&n);
    mnt = fun(m,n);
    printf("The sum from %d to %d is %d.\n",m,n,mnt);
    return 0;
}

int fun(int a,int b)
{
    if(a == b)
    {
        return a;
    }
    return fun(a+1,b) + a;
}