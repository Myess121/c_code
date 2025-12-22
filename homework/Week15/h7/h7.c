#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  
        {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
  
}  
  
int main()  
{   
    int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
  

void change( int n, int m, NODE * head ) 
{  
    int a[10000],b[10000];
    NODE *p;
    int i = 0 ,flag = 0,cnt,t;
    unsigned long long z,x = (unsigned long long)m,y = (unsigned long long)n,k = 1,n1 = 10*(unsigned long long)n;
    if(n == 0)
    {
        return ;
    }
    while(k != 0)
    {
        k = x%y;
        x = y;
        y = k;
    }
    k = m / x;
    x = k;
    while(x % 5 == 0)
    {
        x = x/ 5;
    }
    while(x % 2 == 0)
    {
        x = x / 2;
    }
    if(x == 1)
    {
        flag = 1;
    }else{
        z = 10;
        y = 1;
        while(y != 0)
        {
            y = (z-1) % x;
            z *= 10;
            i ++;
        }
        cnt = i;
        for(i = 0;i<cnt;i++)
        {
            a[i] = n1;
            b[i] = n1 / m;
            n1 = (n1 - b[i]*m)*10;
        }
        while(n1 != a[i-cnt])
        {
            a[i] = n1;
            b[i] = n1 / m;
            n1 = (n1 - b[i]*m)*10;
            i++;
        }
        t= i-1;
        i = 0;
        while(i<cnt)
        {
            p = (NODE *)malloc( sizeof(NODE) );
            p->data = b[t-i];
            p->next = head->next;
            head->next = p;
            i++;
        }
        p = (NODE *)malloc( sizeof(NODE) );
        p->data = cnt;
        p->next = head->next;
        head->next = p;
    } 
} 
 
NODE * find( NODE * head, int * n ) 
{ 
    NODE *p;
    if(head->next == NULL)
    {
        *n = 0;
        return NULL;
    }
    *n = head->next->data;
    head = head ->next;
    p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = head ->next;
    return head->next;
} 