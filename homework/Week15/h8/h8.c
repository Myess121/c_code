#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int m,n,a[105][105],i,j,cnt,flag1 = 0,flag2 = 0;
    scanf("%d %d",&m, &n);
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0;i<m;i++)
    {
        cnt = 0 ;
        for(j = 0;j<n;j++)
        {
            cnt += a[i][j];
        }
        if(cnt % 2 == 1)
        {
            flag1 ++;
        }
    }
    for(j = 0;j<n;j++)
    {
        cnt = 0 ;
        for(i = 0;i<m;i++)
        {
            cnt += a[i][j];
        }
        if(cnt % 2 == 1)
        {
            flag2 ++;
        }
    }
    if(flag1 > flag2)
    {
        printf("%d\n",flag1);
    }else{
        printf("%d\n",flag2);
    }

    return 0;
}