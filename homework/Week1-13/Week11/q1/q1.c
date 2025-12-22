#include <stdio.h>
#include <string.h>

int main ()
{
    int n ,h,i,j;
    char x;
    scanf("%c %d",&x, &n);
    for(i = 0;i<n-1 ;i++)
    {
        printf(" ");
    }
    printf("%c\n",x);
    if(n == 1){
        return 0;
    }
    for(i = 0;i<n-1; i++)
    {
        x += 1;
        if(x == 'z' +1 || x == 'Z' +1){
            x = x - 26;
        }
        for(j = 0;j<n-2-i;j++)
        {
            printf(" ");
        }
        printf("%c",x);
        for(j = 0;j<2*i + 1;j++)
        {
            printf(" ");
        }
        printf("%c\n",x);
    }
    for(i = 1;i<n - 1;i++)
    {
        x -= 1;
        if(x == 'a'-1 || i == 'A'-1){
            x = x + 26;
        }
        for(j = 0;j<i;j++)
        {
            printf(" ");
        }
        printf("%c",x);
        for(j = 0;j<2*(n-1-i) - 1;j++)
        {
            printf(" ");
        }
        printf("%c\n",x);
    }
    x  --;
    if(x == 'a'-1 || i == 'A'-1){
            x = x + 26;
    }
    for(i = 0;i<n-1 ;i++)
    {
        printf(" ");
    }
    printf("%c\n",x);


    return 0;
}