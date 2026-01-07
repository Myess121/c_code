#include <stdio.h>
#include <string.h>
int main ()
{
    int n,m[100],i,j,k,t = 1,flag [100],max,flag2 = 0,max2,flag3 = 0,flag4;
    int a[100][10][10];
    scanf("%d",&n);
    memset(flag , 0 ,sizeof(int));
    for(i = 0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
    max = m [0];
    max2 = 0;
    for(i = 1 ;i<n ;i++)//找最大值，并用flag3标记是否唯一，0代表唯一
    {
        if(max < m[i]){
            max = m[i];
            flag3 = 0;
        }else if(max == m[i]){
            flag3 = 1;
        }
    }
    if(flag3 == 1){
        max2 = max;//最大值不唯一
    }else {
        max2 = 0;//找次大值
        for(i = 0;i<n;i++)
        {
            if(max2<m[i] && m[i] <max)
            {
                max2 = m[i];
            }
        }
    }
    for(k = 0;k<max2;k++)//在加1循环中循环，每个学校的第k个队伍
    {
        for(j = 0;j<10;j++)//每个学校的第k个队伍的第j个队员
        {
            for(i = 0;i<n;i++)//第i个学校
            {
                if(flag[i] == 1)//若学校被标记完，则跳过
                {
                    continue;
                }
                if(m[i] <= k){
                    flag[i] = 1;//标记这个学校已经被标记完了
                    continue;
                }
                a[i][k][j] = t;
                flag4 = i;//最后一个标记的学校
                t++;
            }
        }
    }
    if(max2 != max){
        for(i = 0;m[i] != max;i++);
        if(flag4 == i)//如果最后剩的学校与前面最后一次标记的相同，那么第一个人也要间隔开，否则直接挨着
        {
            t++;
        }
        for(;k<max;k++)
        {
            for(j = 0;j<10;j++)
            {
                a[i][k][j] = t;
                t += 2;
            }
        }
    }
    for(i = 0;i<n;i++)
    {
        printf("#%d\n",i+1);
        for(j = 0;j<m[i];j++)
        {
            for(k = 0; k<10;k++)
            {
                if(k>0){
                    printf(" ");
                }
                printf("%d",a[i][j][k]);
            }
            printf("\n");
        }
    }
    return 0;
}