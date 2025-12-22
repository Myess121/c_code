#include <stdio.h>
#include <string.h>

int main()
{
    char a[5][100];
    int i,j,k,fl,x;
    memset (a,0,sizeof(a));
    for(i = 0;i<5;i++)
    {
        scanf("%s",a[i]);
    }
    for(i = 0;i<5;i++)
    {
        x = 0;
        for(j = 1;j<5;j++)
        {
            for(k = 0;k<100;k++)
            {
                if(a[j][k] < a[x][k]){
                    break;
                }else if(a[j][k] > a[x][k]){
                    x = j;
                    break;
                }
            }
            
        }
        printf("%s\n",a[x]);
        memset (a[x],0,sizeof(a[x]));
    }
}