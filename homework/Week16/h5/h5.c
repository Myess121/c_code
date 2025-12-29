#include <stdio.h>
int main()
{
    int n,a[12][12],i,j,t = 0;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            t++;
            a[i][j] = t;
        }
    }
    for(j = n-1;j>=0;j--)
    {
        for(i = 0;j + i < n;i ++ )
        {
            printf("%3d",a[i][j+i]);
        }
        printf("\n");
    }
    for(i = 1;i<n;i++)
    {
        for(j = 0;j + i < n; j++)
        {
            printf("%3d",a[i+j][j]);
        }
        printf("\n");
    }

    return 0;
}