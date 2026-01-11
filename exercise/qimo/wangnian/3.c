#include <stdio.h>    
int fun(int m, int n);    
int main(int argc, char ** argv)   
{   
    int n, m;   
    scanf("%d%d", &n, &m);   
    printf("%d\n", fun(m, n));   
    return 0;   
}  

int fun (int m, int n)
{
    printf("fun(%d,%d)\n",m,n);
    if(n == 1 || m == 1){
        return 1;
    }else if(n<= m)   {
        return fun(n-1,m) + 1;
    }else{
        return fun(n-m,n-1) + fun(m,n-1);
    }
}