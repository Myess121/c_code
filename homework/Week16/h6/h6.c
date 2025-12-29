#include <stdio.h>
#include <string.h>
int main()
{
    char s[550],x;
    int a[52],i = 0,j,max = 0;
    memset (a,0,sizeof(a));
    memset(s ,0,sizeof(s));
    while((x = getchar()) != '\n')
    {
        if(x >= 'a' && x <= 'z'){
            a[2*(x-'a') + 1] ++;
        }else if(x >= 'A' && x <= 'Z'){
            a[2*(x-'A')] ++;
        }
    }
    for(i = 0;i<52;i++)
    {
        if(a[i] > max){
            max = a[i];
        }
    }
    for(i = 0;i<max;i++)
    {
        for(j = 0;j<26;j++)
        {
            if(a[2*j] + a[2*j + 1] > 0)
            {
                if(a[2*j]>0){
                        if(a[2*j] >= max-i){
                        printf("*");
                    }else{
                        printf(" ");
                    }
                }
                if(a[2*j+1]>0){
                        if(a[2*j+1] >= max-i){
                        printf("*");
                    }else{
                        printf(" ");
                    }
                }
                printf(" ");
            }
        }
        printf("\n");
    }
    for(j = 0;j<26;j++)
    {
        if(a[2*j] + a[2*j + 1] > 0)
        {
            if(a[2*j]>0){
                printf("%c",'A' + j);
            }
            if(a[2*j+1]>0){
                printf("%c",'a' + j);
            }
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}