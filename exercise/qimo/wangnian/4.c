#include "stdio.h"
#include "stdlib.h"

struct node
{   int  data;
    struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;

void outlist( PNODE );
void moveNode( PNODE );   //The function is wating for your.

int main(int argc, char ** argv )
{
    int num=1;
    PNODE head, p;

    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1; //Create a head node

    while ( num!=0 )    //Create the List
    {   scanf("%d", &num);
        if ( num!=0 ) {
            p = (PNODE)malloc( sizeof(NODE) );
            p->data = num;
            p->next = head->next;
            head->next = p;
        }
    }

//  outlist( head );
    moveNode( head );
    printf("Result: ");
    outlist( head );
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

void moveNode(PNODE head)   
{
    PNODE p = head,end = head,p1,END;
    while(end->next != NULL)
    {
        end = end->next;
    }
    END = end; 
    p1 = p;
    p = p->next;
    while(p != END )
    {  
        if(p->data % 2 == 1)
        {
            p1->next = p->next;
            p->next = end->next;
            end->next = p;
            end = end->next;
            p = p1;
        }else{
            p1 = p;
        }
        p = p->next;
    }
    if(p->data % 2 == 1 && p->next !=NULL)
    {
        p1->next = p->next;
        p->next = end->next;
        end->next = p;
        end = end->next;
        p = p1;
    }
    
}
