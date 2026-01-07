#include <stdio.h>

int main ()
{
    int x,n = 0,m,i,s[11] = {0,1,1,1,2,2,3,3,3,4,4},a[11] = {0,0,0,0,0,0,0,0,0,0,0};
    char st[11][20] = {"0","Table-water","Table-water","Table-water",
    "Coca-Cola","Milk","Beer","Oringe-Juice","Sprite","Oolong-Tea","Green-Tea"};
    do{
        scanf("%d",&x);
        if(x == -1){
            break;
        }
        n += x;
    }while(1);
    m = n;
    do{
        scanf("%d",&x);
        if(x == -1)
        {
            break;
        }
        a[x] ++;
        m -= s[x];
        if(m<0){
            printf("Insufficient money");
            return 0;
        }
    }while(1);
    printf("Total:%dyuan,change:%dyuan\n",n,m);
    for(i = 1;i<=10;i++)
    {
        if(a[i] != 0)
        {
            printf("%s:%d;",st[i],a[i]);
        }
    }


    return 0;
}