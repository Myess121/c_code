#include <stdio.h>

int main ()
{
    int a[5],m,n,i,j,k,l,flag = 0;
    scanf("%d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&m,&n);
    for(i = 0;i<=m/a[0];i++)
    {
        for(j = 0;j<=(m - a[0]*i)/a[1]; j++)
        {
            for(k = 0;k<=(m - a[0]*i - a[1]*j)/a[2];k++)
            {
                for(l = 0;l<=(m - a[0]*i - a[1]*j - a[2]*k)/a[3] ; l++)
                {
                    if(i + j+k+l>n){
                        continue;
                    }
                    if(a[0]*i + a[1]*j + a[2]*k + a[3]*l + a[4]*(n-i-j-k-l) == m){
                        printf("%d,%d,%d,%d,%d\n",i,j,k,l,n-i-j-k-l);
                        flag = 1;
                    }
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\n");
    }
    return 0;
}