#include <stdio.h>

int main()
{
    int n,a,i,j,flag = 1;
    char x,y;
    scanf("%d %c",&n,&x);
    printf("%c",x);
    if(n == 1)
    {
        printf("\n");
        return 0;
    }
    y = (3*(char)n)%26 -4 + x;
    while(y>'Z')
    {
        y -= 26;
    }
    for(i = 0;i<2*n - 3;i++)
    {
        printf("  ");
    }
    printf(" %c\n",x);
    
    for(i = 0;i< n-2;i++)
    {
        x++;
        if(x>'Z')
        {
            x = 'A';
        }
        printf("%c",y);
        
        for(j = 0; j<i;j++)
        {
            printf("  ");
        }
        printf(" %c",x);
        for(j = 0;j<2*n-5-2*i;j++)
        {
            printf("  ");
        }
        printf(" %c",x);
        for(j = 0; j<i;j++)
        {
            printf("  ");
        }
        printf(" %c\n",y);
        y--;
        if(y<'A'){
            y = 'Z';
        }
    }
    for(i = 0;i<n-1;i++)
    {
        if(flag == 1){
            printf("%c",y);
            flag = 0;
        }else{
            printf(" %c",y);
        }
        y--;
        if(y<'A'){
            y = 'Z';
        }
    }
    for(i = 0;i<n;i++)
    {
        printf(" %c",y);
        y ++;
        if(y>'Z'){
            y = 'A';
        }
    }
    printf("\n");

    return 0;
}