#include <stdio.h>  
struct nn  
{  int no;     
   int num;     
};  
  
typedef struct nn DATA;  
  
int number( char * , DATA []);  
  
int main( )  
{     
   DATA b[100];    
   char sa[500];    
   int i, n;    
   gets( sa );   
   n = number( sa, b );   
   for ( i=0; i<n; i++ )   
       printf("%d %d\n", b[i].num, b[i].no );   
   return 0;  
}  
  

int number( char * str, DATA a[] ) 
{ 
    int i = 0,n,max = -1 ,min ,cnt,n1 = 1,flag = 0;
    char* p = str, *p1 = str;
    while(*p != '\0')
    {
        while(*p != ' '&&*p != '\0'){
            p++;
        }
        n = 0;
        while(p1 != p ){         
            n = 10 * n + *p1 - '0';
            p1++;
        }
        a[i].num = n;
        if(max < n){
            max = n;
        }
        i ++;
        if(*p == '\0'){
            break;
        }
        p1 ++;
        p ++;
    }
    cnt = i;
    for(i = 0;i<cnt;i++)
    {
        a[i].no = 0;
    }
    while(flag == 0)
    {
        flag = 1;
        min = max;
        for(i = 0;i<cnt;i++)
        {
            if(a[i].num < min&&a[i].no == 0)
            {
                min = a[i].num;
            }
        }
        for(i = 0;i<cnt;i++)
        {
            if(a[i].num == min && a[i].no == 0)
            {
                a[i].no = n1;
                flag = 0;
                n1++;
                break;
            }
        }
    }
    return cnt;
}