#include <stdio.h>  
void sort(int *, int, int);  
int input(int *, int );  
int output(int *, int );  
int main()  
{  
// 输入n（n<100)个整数，按照指定的方式（升序或降序）进行排序  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);  
    input(a, n);  
    sort(a, n, flag); // flag=0：升序，flag=1：降序  
    output(a, n);  
    return 0;  
}  
int input (int *a,int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
int output (int *a,int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d,",a[i]);
    }
    printf("\n");
}
void sort(int *a,int n,int flag)
{
    int i,fla = 1,t;
    if(flag == 0)
    {
        flag --;
    }
    while (fla == 1)
    {
        fla = 0;
        for(i = 0;i<n-1;i++ )
        {
            if ((a[i] - a[i+1])*flag < 0)
            {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                fla = 1;
            }
        }
    }
}