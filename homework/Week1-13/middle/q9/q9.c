#include <stdio.h>

int main()
{
    int a,b,n,i,j;
    scanf("%d %d",&n,&a);
    b = (6*n-7+a)%10;
    
    for(i = 0; i<n-1; i++)
    {
        printf(" ");
    }
    printf("%d",a);
    if(n == 1){
        printf("\n");
        return 0;
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d",b);
        b--;
        if(b<0){
            b = 9;
        }
    }
    printf("\n");
    for(i = 0;i<n-2;i++)
    {
        a ++;
        if(a>9){
            a = 0;
        }
        for(j = 0;j<n-2-i;j++)
        {
            printf(" ");
        }
        printf("%d",a);
        for(j = 0;j<n + 2*i;j++)
        {
            printf(" ");
        }
        printf("%d\n",b);
        b--;
        if(b<0){
            b = 9;
        }
    }
    for(i=0;i<3*n - 2;i++)
    {
        a ++;
        if(a>9){
            a = 0;
        }
        printf("%d",a);
    }
    printf("\n");
    return 0;
}