#include <stdio.h>
#include <string.h>
void print(int a);
int main()
{
    int x,a[5],i,flag;
    while(1){
        scanf("%d",&x);
        if(x == 0)
        {
            return 0;
        }
        memset(a,0,sizeof(a));
        i = 4;
        while(x!=0){
            a[i] = x%10;
            x /= 10;
            i--;
        }
        flag = 0;
        for(i = 0;i<5;i++)
        {
            if(flag != 0){
                printf(" ");
            }
            print(a[i]);
            flag ++;
        }
        printf("\n");
    }
    return 0;
}
void print(int a)
{
    switch (a)
    {
        case 0:
        printf("7D");
        break;
        case 1:
        printf("50");
        break;
        case 2:
        printf("37");
        break;
        case 3:
        printf("57");
        break;
        case 4:
        printf("5A");
        break;
        case 5:
        printf("4F");
        break;
        case 6:
        printf("6F");
        break;
        case 7:
        printf("54");
        break;
        case 8:
        printf("7F");
        break;
        case 9:
        printf("5F");
        break;

    }
}