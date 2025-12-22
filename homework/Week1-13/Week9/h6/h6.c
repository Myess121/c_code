#include <stdio.h>

int main()
{
    int a[500][500];
    int n,b,flag = 0,i,j,k,max,fla;
    scanf("%d %d",&n,&b);
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<b;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        max = a[i][0];
        for(j = 1;j<b;j++)
        {
            if(max<a[i][j]){
                max = a[i][j];
            }
        }
        for(j = 0;j<b;j++)
        {
            if(a[i][j]== max){
                fla = 0;
                for(k=0;k<n;k++)
                {
                    if(a[k][j] < max){
                        fla = 1;
                        break;
                    }
                }
                if(fla != 1){
                    printf("Point:a[%d][%d]==%d\n",i,j,max);
                    flag = 1;
                }
                
            }
        }
    }
    if(flag == 0)
    {
        printf("No Point\n");
    }

    return 0;
}