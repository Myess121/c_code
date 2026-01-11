#include <stdio.h>

int main ()
{
    char a[] = "BCDFGHJKLMNPQRSTVWXYZ",x;
    int n,i,k,j;
    scanf("%d %c",&n ,&x);
    switch (x-'A'){
        case 0:
        case 4:
        case 8:
        case 14:
        case 20:
        x ++;
    }
    for(k = 0;a[k] != x;k++);
    for(i = 0;i<2 * n - 1;i++)
    {
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
    }
    printf("\n");
    if(n == 1){
        return 0;
    }
    for(i = 0;i <n-2;i++)
    {
        for(j = 0;j< i+1;j++)
        {
            printf(" ");
        }
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
        for(j = 0;j<2*n - 5 -2*i;j++)
        {
            printf(" ");
        }
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
        printf("\n");
    }
    for(j = 0;j< n-1;j++)
    {
        printf(" ");
    }
    printf("%c",a[k]);
    k++;
    if(k > 20)
    {
        k = 0;
    }
    printf("\n");
    for(i = 0;i <n-2;i++)
    {
        for(j = 0;j<n-2-i;j++)
        {
            printf(" ");
        }
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
        for(j = 0;j<2*i + 1;j++)
        {
            printf(" ");
        }
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
        printf("\n");
    }
    for(i = 0;i<2 * n - 1;i++)
    {
        printf("%c",a[k]);
        k++;
        if(k > 20)
        {
            k = 0;
        }
    }
    printf("\n");
    
    return 0;
}