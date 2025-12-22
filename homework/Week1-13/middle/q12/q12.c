#include <stdio.h>
int main()
{
    int n,i,j,k,cnt=0,m;
    scanf("%d",&n);//羊肉5快  *4 = 20，馒头2，，*2 = 4，茄子10快一盘
    for(i = 0 ; i<=(n/20);i++)
    {
        for(j = 0;j<=((n - 20*i)/4);j++)
        {
            m = n - 20*i - 4*j;
            if(m%10==0){
                k = m / 10;
                cnt ++;
                printf("%d:%d,%d,%d\n",cnt,4*i,2*j,k);
            }
        }
    }
    if(cnt == 0){
        printf("No!\n");
    }

    return 0;
}