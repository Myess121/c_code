#include <stdio.h>
#include <string.h>
int search_in();
typedef struct a1
{
    int a[2];
    struct a1 *next;
} st1;
typedef struct a2{
    struct a2* next;
    struct a1 *head;
} st2;
st2 HEAD1,*p1;
st1 head,*p;
int n,x1,x2,y2,x3,y3,y11;
int main ()
{
    int i,j,k,x,y;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y11,&x2,&y2,&x3,&y3);
        if((x1-x2)*(y11+y2)+(x2-x3)*(y2+y3)+(x3-x1)*(y3+y11)<0){
            x = x3;
            y = y3;
            x3 = x2;
            y3 = y2;
            x2 = x;
            y2 = y;
        }
        search_in();
    }
    return 0;
}
int search_in()
{
    int *a1,*a2;
    p1 = HEAD1.next;
    while(p1 != NULL)
    {
        p = p1->head;
        while(p != NULL)
        {
            a1 = p->a;
            if(p->next->next != NULL){
                a2 = p->next->a;
            }else {
                a2 = p1->head->a;
            }
            //放弃
        }
    }
}