#include <stdio.h>

int main()
{
    int n,flag=1,i,b;
    int a[100];
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(flag == 1)
    {
        flag = 0;
        for(i = 1;i<n;i++)
        {
            if(a[i-1]>a[i]){
                b = a[i];
                a[i] = a[i-1];
                a[i-1] = b;
                flag = 1;
            }
        }
    }
    printf("%d",a[0]);
    for(i=1;i<n;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}