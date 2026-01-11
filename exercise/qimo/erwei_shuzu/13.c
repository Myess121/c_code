#include <stdio.h>
#include <string.h>

int main ()
{
    int a[100][100],n,i,j,x;
    memset(a,0,sizeof(a));
    char c;
    scanf("%c %d",&c,&n);
    getchar();
    for(i = n-1;i>=0 ;i--)
    {
        for(j = n-1;j>=0;j--)
        {
            x = getchar();
            if(x == '@'){
                a[i][j] = 1;
            }
        }
        getchar();
    }
    for(i = 0;i<(n+1)/2 ;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(a[i][j] != a[n-1-i][n-1-j])
            {
                goto end;
            }   
        }
    }
    printf("bu yong dao le\n");
    end:
    for(i = 0;i<n ;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(a[i][j] == 0)
            {
                printf(" ");
            }else{
                printf("%c",c);
            }
        }
        printf("\n");
    }
    return 0;
}