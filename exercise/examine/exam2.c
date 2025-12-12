#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp (const void * p1,const void * p2);
int main()
{
    int n,i,j,x[10002],y[10005],cnt = 0,t;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    qsort(y,n,sizeof(int),cmp);
    qsort(x,n,sizeof(int),cmp);
    t = y[(n+1) / 2 - 1];
    for(i = 0;i<n;i++)
    {
        cnt = cnt + abs(y[i]- t);
        x[i] = x[i] - i;
    }
    qsort(x,n,sizeof(int),cmp);
    t = x[(n+1) / 2 - 1];
    if(t < -10000)
    {
        t= -10000;
    }
    for(i = 0;i<n;i++)
    {
        cnt = cnt + abs(x[i] - t );
    }
    printf("%d\n",cnt);
    return 0;
}

int cmp (const void * p1,const void * p2)
{
    return (*(int *)p1 - *(int *)p2);
}