#include <stdio.h>
#include <string.h>
int max(int n,char a[5][100]);
int main()
{
    char a[5][100];
    int i,j,k,fl;
    memset (a,0,sizeof(a));
    for(i = 0;i<5;i++)
    {
        scanf("%s",a[i]);
    }
    for(j = 0;j<5;j++)
    {
        for(i=0;i<100;i++)
        {
            fl = max(i,a);
            if(fl == -1){
                continue;
            }else{
                printf("%s\n",a[fl]);
                memset(a[fl],0,sizeof(a[fl]));
                break;
            }
        }
    }

    return 0;
}
int max(int n,char a[5][100])
{
    char x;
    int k,flag = 0,flag1;
    x = a [0][n];
    for(k = 1;k<5;k++)
    {
        if(x<a[k][n]){
            x = a[k][n];
        }
    }
    for(k=0;k<5;k++)
    {
        if(a[k][n] == x)
        {
            flag ++;
            flag1 = k;
        }
    }
    if(flag == 1){
        return flag1;
    }
    return -1;
}