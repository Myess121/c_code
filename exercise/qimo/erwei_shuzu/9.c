#include <stdio.h>
#include <string.h>

int main ()
{
    int n ,i,j,k,x1,x2,y1,y2,flag = 0,cnt = 0,flag2;
    char a[11][11];
    scanf("%d",&n);
    for(i = 1;i <= 2*n;i++)
    {
        for(j = 1;j<=2*n;j++)
        {
            scanf(" %c",&a[i][j]);
        }
    }
    scanf("%d",&k);
    while(k>0)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(a[x1][y1] == a[x2][y2] && a[x1][y1] != '*' && (x1 != x2||y2 != y1))
        {
            a[x1][y1] = '*';
            a[x2][y2] = '*';
            cnt ++;
            if(cnt == 2*n*n){
                printf("Congratulations!\n");
                return 0;
            }
            for(i = 1;i<=2*n;i++)
            {
                flag2 = 0;
                for(j = 1;j<= 2*n;j++)
                {
                    if(flag2 != 0)
                    {
                        printf(" ");
                    }
                    printf("%c",a[i][j]);
                    flag2 ++;
                }
                printf("\n");
            }
        }else{
            if(flag == 2)
            {
                printf("Uh-oh\n");
                printf("Game Over\n");
                return 0;
            }
            printf("Uh-oh\n");
            flag ++;
        }
        k--;
    }
    return 0;
}