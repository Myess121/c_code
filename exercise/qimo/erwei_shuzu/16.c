#include <stdio.h>
int main ()
{
    int a[6][6],i,j,x,y,m,n,max;
    scanf("%d%d",&m,&n);
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    max = a[0][0];
    x = 0;
    y = 0;
    for(i = 0;i<m;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(max<a[i][j])
            {
                max = a[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n%d %d\n",max,x,y);
    return 0;
}
