#include <stdio.h>
#include <string.h>
int main ()
{
    int a[10][12];
    int n,i,j;
    memset (a,0,sizeof(a));
    a[0][1] = 1;
    scanf("%d",&n);
    for(i = 1;i<n;i++)
    {
        for(j = 1;j<=i+1;j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n-1-i;j++)
        {
            printf(" ");
        }
        for(j = 1;j<=i+1;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}