#include <stdio.h>
#include <string.h>

int main ()
{
    int a[100][100],i,j,n,m,flag;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(i = 0;i<n;i++)
    {
        a[i][0] = 1;
        a[n+m-1 - i][m+n-1] = 1;
        a[i][i] = 1; 
        a[n+m-1 - i][n+m-1 - i] = 1;
    }
    i = n - 1;
    for(j = n-1;j>0;j--)
    {
        a[i][j] = 1;
        a[n+m-1 - i ][n+m-1 - j] = 1;
    }
    for(i= 0;i<n+m;i++)
    {
        flag = -1;
        for(j = 0;j<n+m;j++)
        {
            if(a[i][j] == 1)
            {
                flag = j;
            }
        }
        for(j = flag+1;j<n+m;j++)
        {
            a[i][j] = 2;
        }
    }
    for(i = 0;i<n+m;i++)
    {
        for(j = 0;j<n+m;j++)
        {
            if(a[i][j] == 0)
            {
                printf(" ");
            }else if(a[i][j] == 1){
                printf("*");
            }
        }
        printf("\n");
    }


    return 0;
}