#include <stdio.h>
#include <string.h>
void search(char *p,char * x);
int main()
{
    int i = 0,j;
    char a[200];
    memset(a,0,sizeof(a));
    while((a[i] = getchar()) != '\n')
    {
        i++;
    }
    a[i] = 0;
    search(a,"a");
    search(a,"e");
    search(a,"i");
    search(a,"o");
    search(a,"u");
    search(a,"A");
    search(a,"E");
    search(a,"I");
    search(a,"O");
    search(a,"U");
    printf("\n");

    return 0;
}
void search(char *p,char * x)
{
    while (p !=NULL)
    {
        p = strstr(p,x);
        if(p == NULL){
            return;
        }else{
            printf("%s",x);
            p++;
        }
    }
}