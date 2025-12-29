#include <stdio.h>
int fun (int x);
int main ()
{
    int n,i;
    scanf("%d",&n);
    for(i = 2;i<n;i++)
    {
        if(fun(i) == 1)
        {
            if(fun(n-i) == 1)
            {
                printf("%d=%d+%d\n",n,i,n-i);
                return 0;
            }
        }
    }
    return 0;
}
int fun (int x)
{
    int j;
    if(x == 2){
        return 1;
    }
    for(j = 2;j<=x/2;j++)
    {
        if(x % j == 0)
        {
            return 0;
        }
    }
    return 1;
}