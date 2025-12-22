#include <stdio.h>  
void sort(int *, int, int (*)(int, int));  
int input(int *, int );  
int output(int *, int );  
int up(int, int);       // a<b:1； a=b:0；a>b:-1反序   
int down(int, int);     // a<b:-1；a=b:0；a>b:1 正
  
int main()  
{  
    int n, flag, a[100];  
    scanf("%d%d", &n, &flag);   // n：数组元素数量； flag=0：升序，flag=1：降序   
    input(a, n);  
    if ( flag==0 )  
        sort(a, n, up);     // 0：升序，1：降序  
    else   
        sort(a, n, down);  
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
int up(int a, int b)
{
    if(a < b) return 1;
    if(a == b) return 0;
    return -1;
}
int down(int a, int b)
{
    if(a < b) return -1;
    if(a == b) return 0;
    return 1;
}
void sort(int *a, int n, int (*fun)(int, int))
{
    int i,fla = 1,t;
    while (fla == 1)
    {
        fla = 0;
        for(i = 0;i<n-1;i++ )
        {
            if (fun(a[i],a[i+1]) < 0)
            {
                t = a[i];
                a[i] = a[i+1];
                a[i+1] = t;
                fla = 1;
            }
        }
    }
}