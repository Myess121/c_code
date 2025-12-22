#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct grade{
    char arr[30];
    int a;
} grade;
grade g[100];
int main()
{
    int n,i,j,flag = 0;
    char x;
    grade t;
    scanf("%d",&n);
    getchar();
    for(i = 0;i<n;i++)
    {
        j = 0;
        while((x = getchar()) != ',')
        {
            g[i].arr[j] = x;
            j++;
        }
        scanf("%d",&g[i].a);
        getchar();
    }
    while (flag == 0)
    {
        flag = 1;
        for(i = 0;i<n-1;i++)
        {
            if(g[i].a<g[i+1].a){
                t = g[i];
                g[i] = g[i+1];
                g[i+1] = t;
                flag = 0;
            }
        } 
    }
    
    for(i =0;i<n;i++)
    {
        printf("%s,%d\n",g[i].arr,g[i].a);
    }
    return 0;
}

/*int cmp(const void* x,const void *y)
{
    if(((grade*)x)->a == ((grade*)y)->a){
        return strcmp(((grade*)x)->arr,((grade*)y)->arr);
    }else{
        return ((grade*)y)->a - ((grade*)x)->a;
    }
}*/