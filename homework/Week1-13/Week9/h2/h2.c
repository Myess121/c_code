#include <stdio.h>

int main()
{
    int n,m,k,a[10000],b[10000],c[10000];
    int x,i,j;
    double p = 1;
    scanf("%d %d %d",&n,&m,&k);
    for(i = 0;i<n-1;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    for(i = 0;i<n-1;i++)
    {
        k = k + a[i] - b[i];
        printf("%.3lf\n",(double)k / m);
        if((double)k / m < p){
            p = (double)k / m;
            j = 0;
            c[j] = i;
            j ++;
        }else if((double)k / m == p){
            c[j] = i;
            j++;
        }
    }
    for(i = 0;i<=j-1;i++)
    {
        printf("%d,",c[i]+1);
    }
    printf("\n");


    return 0;
}