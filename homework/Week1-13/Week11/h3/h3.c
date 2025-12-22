#include <stdio.h>
#include <string.h>

int main()
{
    char a[102][102];
    int i,j,n,m,flag,flag2 = 1;
    while(1)
    {
        memset (a,0,sizeof(a));
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0){
            return 0;
        }
        for(i = 1; i<=n; i++)
        {
            scanf("%s",a[i]+1);
        }
        if(flag2 != 1){
            printf("\n");
            printf("Field #%d:\n",flag2);
        }else{
            printf("Field #1:\n");
        }
        for(i = 1;i<=n;i++)
        {
            for(j = 1;j<=m;j++)
            {
                flag = 0;
                if(a[i][j] == '*'){
                    printf("*");
                    continue;
                }
                if(a[i][j-1] == '*'){
                    flag ++;
                }
                if(a[i][j+1] == '*'){
                    flag ++;
                }
                if(a[i+1][j-1] == '*'){
                    flag ++;
                }
                if(a[i+1][j] == '*'){
                    flag ++;
                }
                if(a[i+1][j+1] == '*'){
                    flag ++;
                }
                if(a[i-1][j-1] == '*'){
                    flag ++;
                }
                if(a[i-1][j] == '*'){
                    flag ++;
                }
                if(a[i-1][j+1] == '*'){
                    flag ++;
                }
                printf("%d",flag);
            }
            printf("\n");
        }
        flag2++;
    }
    return 0;
}