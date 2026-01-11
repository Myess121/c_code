#include <stdio.h>
int main ()
{
    int a[30000];
    int n,i,w,k = 0;
    scanf("%d%d",&w,&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0;i<n;i++)
    {
        k += a[i];
        w += k;
        if(i>0){
            printf(" ");
        }
        printf("%d",w);
    }
    printf("\n");
    return 0;
}