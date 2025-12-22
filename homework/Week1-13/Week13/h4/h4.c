#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
  
int * input( int );           
int PrimCount( int *, int );      
int isPrim( int );   
  
/* 
int * input(int n) // 输入n个整数保存在动态申请的空间中  
{ 
// n：需要处理的整数数量  
// 函数功能：申请存储n个整数的空间，读入n个整数保存在该空间中  
// 函数返回值：指向该内存空间的指针  
// 以下函数体请你编写  
 
} 
 
int PrimCount( int *p, int n)  // 统计n个整数中的素数数量  
{ 
// p：指向待统计的数组首地址  
// n：数组中保存的数据数量  
// 函数功能：统计指针p所指空间中素数的数量  
// 函数返回值：统计结果 
// 以下函数体请你编写  
 
} 
*/  
  
int isPrim(int x)  
{   int i;  
    if ( x==2 ) return 1;       // 是素数，返回1  
    if ( x<=1 || x%2==0 )    return 0;   // 不是素数，返回0   
    for ( i=3; i<=sqrt(x); i+=2 )  
        if ( x%i==0 )   return 0;   // 不是素数，返回0   
    return 1;           // 是素数，返回1   
}  
  
int main()  
{   int n, count, *p;  
  
    scanf("%d", &n);        // 接受整数数量n  
    p = input( n );         // 调用函数输入n个整数   
    count = PrimCount( p, n );  // 对素数进行计数   
    printf("PrimCount=%d\n", count);  
    return 0;  
}  
int * input( int n )
{
    int i;
    int *a = (int*) malloc(n * sizeof(int));
    for(i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    return a;
}
int PrimCount( int *a, int n)
{
    int i,cnt = 0;
    for(i = 0;i<n;i++)
    {
        cnt += isPrim(a[i]);
    }
    return cnt;
}