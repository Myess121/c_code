#include <stdio.h>
#include <string.h>

int main()
{
    int x1,y1,x2,y2,n,flag = 0,i,a;
    int x[1000],y[1000];
    memset (x,0,sizeof(x));
    memset (y,0,sizeof(y));
    scanf("%d,%d %d,%d %d",&x1,&y1,&x2,&y2,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d,%d",&x[i],&y[i]);
    }
    for(i = 0;i<n;i++)
    {
        a = (y1-y2)*x[i] + (x2-x1)*y[i] + x1*y2 -x2 *y1;
        if(a == 0){
            printf("%d,%d\n",x[i],y[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("NoOut.\n");
    }
    return 0;
}