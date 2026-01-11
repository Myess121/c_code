#include <stdio.h>
int main ()
{
    int a[6][6],i,j,n;
    scanf("%d",&n);
    for(j = 0;j<n;j++)
    {
        for(i = 0;i<n;i++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}