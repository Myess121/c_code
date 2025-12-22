#include <stdio.h>
#include <string.h>
int main()
{
    int i,n,j,flag,n1 = 0;
    char a[10000],b[10000];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s",a);
    scanf("%s",b);
    for(i=0;i<10000;i++)
    {
        if(a[i] == 0){
            break;
        }
    }
    n = i-1;
    for(j = 0;j<=n;j++)
    {
        flag = 0;
        for(i = 0;i<=j;i++)
        {
            if(a[n-j+i] != b[i])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            n1 = j;
        }
    }
    if(n1 == 0&&a[n] != b[0])
    {
        printf("\n");
        return 0;
    }
    for(i = 0;i<=n1;i++)
    {
        printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}