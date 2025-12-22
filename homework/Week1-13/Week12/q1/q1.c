#include <stdio.h>


int main ()
{
    int n,i,j;
    char x,y,z;
    scanf("%d %c",&n,&x);
    if(n % 2 == 0){
        printf("Input error!\n");
        return 0;
    }
    if(x>'z'||x<'A'||(x>'Z'&&x<'a')){
        printf("Input error!\n");
        return 0;
    }
    if(x>='a'){
        x -= 32;
    }
    y = x;
    for(i = 0;i<n;i++)
    {
        printf("%c",x);
        if(i == n/2){
            z = x;
        }
        x ++;
        if(x > 'Z'){
            x -= 26;
        }
    }
    printf("\n");
    if(n == 1)
    {
        return 0;
    }
    for(i = 0;i<n-2;i++)
    {
        y++;
        if(y > 'Z'){
            y -= 26;
        }
        printf("%c",y);
        for(j = 0;j<n/2 - 1;j++)
        {
            printf(" ");
        }
        z++;
        if(z > 'Z'){
            z -= 26;
        }
        printf("%c",z);
        for(j = 0;j<n/2 - 1;j++)
        {
            printf(" ");
        }
        printf("%c\n", x );
        x ++;
        if(x > 'Z'){
            x -= 26;
        }
    }
    for(i = 0;i<n;i++)
    {
        y++;
        if(y > 'Z'){
            y -= 26;
        }
        printf("%c",y);
    }
    printf("\n");
    

}