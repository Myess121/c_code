#include <stdio.h>  
  
int sumn( int n, int *flag);  
  
int main()  
{   int n, nf=0;  
    scanf("%d",&n);  
    printf("%d\n", sumn(n, &nf) );  
    if (nf!=n)  
        printf("Error:%d\n",nf);  
    return 0;  
}  
int sumn( int n, int *flag)
{
    if(*flag != n)
    {
        (*flag)++;
        return (n-(*flag) + 1)*(n-(*flag) + 2) +  sumn(n,flag);
    }
    return 0;
}