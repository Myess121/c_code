#include <stdio.h>
int pai(int n ,int a[1000]);
int main()
{
    int a[1000],b[1000],n,m,i,j=0,sum = 0;
    scanf("%d %d",&n,&m);
    for(i = 0;i <n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    pai(n,a);
    pai(m,b);
    for(i = 0;i<m;i++)
    {
        if(b[i]>=a[j]){
            sum = sum + b[i];
            if(j == n-1){
                printf("%d\n",sum);
                return 0;
            }
            j++;
        }
    }
    printf("bit is doomed!\n");
    return 0;
}

int pai(int n ,int a[1000])
{
    int b,i,flag=1; 
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
}