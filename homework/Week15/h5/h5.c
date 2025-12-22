#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct sdata  
{  int num;  
   struct sdata *next;  
} ;  
typedef struct sdata SNODE;  
void movenode( SNODE *, int );  
  
void setlink( SNODE * head, int n )  
{     
    SNODE *p;  
  
    while ( n > 0 )  
    {   p = ( SNODE * ) malloc( sizeof( SNODE ) );  
        p->num = n;  
        p->next = head->next;  
        head->next = p;  
        n --;  
    }  
}  
  
void outlink( SNODE * head )  
{  
    while( head->next != NULL )  
    {  
        head = head->next;  
        printf( "%d,", head->num );  
    }  
    return;  
}  
  
int main( )  
{   int n, m;  
    SNODE * head = NULL;  
  
    scanf("%d%d", &n, &m );  
    head = ( SNODE * ) malloc( sizeof( SNODE ) );  
    head->num = -1;  
    head->next = NULL;  
    setlink( head, n );  
  
    movenode( head, m );   /* This is waiting for you. */  
  
    outlink( head );  
    printf("\n");  
    return 0;  
} 

void movenode( SNODE *h, int m)
{
    if(m == 0)
    {
        return;
    }
    SNODE *p = h,*p1;
    while(m!=1)
    {
        p = p->next;
        if(p == NULL)
        {
            return ;
        }
        m --;
    }
    if(p->next == NULL)
    {
        return ;
    }
    p1 = p->next;
    p->next = p->next->next;
    p1->next = h->next;
    h->next = p1;
}