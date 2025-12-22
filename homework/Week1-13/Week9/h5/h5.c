#include <stdio.h>

int main(){
    int a,b,i,j,cnt = 0,flag;
    int x[10][10],y[10][10],z[10][10],w[10][10];
    scanf("%d*%d",&a,&b);
    for(i = 0;i<b;i++)
    {
        for(j = 0;j<a;j++)
        {
            scanf("%d",&x[i][j]);
        }
    }
    for(i = 0;i<b;i++)
    {
        for(j = 0;j<a;j++)
        {
            scanf("%d",&y[i][j]);
        }
    }
    for(i = 0;i<b;i++)
    {
        for(j = 0;j<a;j++)
        {
            z[i][j] = x[i][j] | y[i][j];
            w[i][j] = x[i][j] & y[i][j];
        }
    }
    for(i = 0;i<b;i++)
    {
        for(j = 0;j<a;j++)
        {
            if(z[i][j] == 1)
            {
                cnt ++;
            }
        }
    }
    printf("烟花爆炸范围为%d.\n",cnt);
    for(i = 0;i<b;i++)
    {
        flag = 0;
        for(j = 0;j<a;j++)
        {
            if(flag == 0){
                printf("%d",w[i][j]);
                flag = 1;
            }else{
                printf(" %d",w[i][j]);
            }
            
        }
        printf("\n");
    }

    return 0;
}