#include <stdio.h>

int gcd (int m,int n);
int main()
{
    int m,n,a;
    scanf("%d %d",&m,&n);
    a = gcd(m,n);
    printf("%d\n",a);
    return 0;
}

int gcd (int m,int n)
{
    if(n > m)
    {
        return gcd(n,m);
    }
    if(n == 0)
    {
        return m;
    }
    return gcd(n,m % n);
}