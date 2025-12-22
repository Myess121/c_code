#include <stdio.h>

int main()
{
    int a[6][6],b[6][6];
    int i,j,flag;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            b[i][j] = a[j][5-i];
        }
    }
    for(i=0;i<6;i++)
    {
        flag = 0;
        for(j=0;j<6;j++)
        {
            
            if(flag == 0)
            {
                printf("%d",b[i][j]);
                flag = 1;
            }else{
                printf(" %d",b[i][j]);
            } 
        }
        printf("\n");
    }
    return 0;
}