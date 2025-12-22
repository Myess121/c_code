#include <stdio.h>
#include <string.h>
int fun(char *p,int a,int b);
int main()
{
    int i = 0;
    char a[1000];
    do{
        a[i] = getchar();
        i ++;
    }
    while(a[i-1] != '\n');
    if(i == 1)
    {
        printf("Yes\n");
        return 0;
    }
    if(fun(a,0,i-2) == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}

int fun(char *p,int a,int b)
{
    if(a + 1 >= b){
        if(p[a] == p[b]) {
            return 1;
        }else{
            return 0;
        }
    }
    if(fun(p,a+1,b-1) == 0){
        return 0;
    }
    if(p[a] == p[b]){
        return 1;
    }
    return 0;
}