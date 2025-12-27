#include <stdio.h>
int main ()
{
    int i ,n,a = 4,b;
    scanf("%d",&n);
    for(i = 2015;i<=n;i++)
    {
        a ++;
        if((i%100!=0&&i%4==0)||i%400 == 0){
            a++;
        }
    }
    while(a>=7)
    {
        a -= 7;
    }
    if(a == 0){
        printf("8\n");
    }else{
        printf("%d\n",15-a);
    }

    return 0;
}