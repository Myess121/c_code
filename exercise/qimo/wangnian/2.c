#include <stdio.h>

int main()
{
    int n,m,x,i;
    scanf("%d%d%d",&n,&m,&x);
    for(i = 0;n-i>0;i++)
    {
        x = x - (n-i);
        if(x<=0)
        {
            printf("能爬出井，用时%d天\n",i+1);
            return 0;
        }
        x = x + m;
    }
    printf("爬不出去\n");
}