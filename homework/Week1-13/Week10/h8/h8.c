#include <stdio.h>
#include <string.h>

int main(){
    int n,i=0,j,flag = 0;
    char a[101];
    memset(a,0,sizeof(a));
    do{
        a[i] = getchar();
        i ++ ;
    }while(a[i-1] != '\n');
    a[i-1] = 0;
    for(i = 0;i<100;i++)
    {
        flag = 0;
        if(a[i]==0){
            break;
        }
        for(j = 0;j<i;j++)
        {
            if(a[j] == a[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("%c",a[i]);
        }
    }
    printf("\n");

    return 0;
}