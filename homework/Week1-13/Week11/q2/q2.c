#include <stdio.h>
#include <string.h>

int main()
{
    int i,n,cnt = 1,j,k,c,flag = 0;
    double a;
    scanf("%d %lf",&n,&a);
    c = (int)(10 * a);
    for(i = c / 100;i>= 0; i--)
    {
        for(j = (c-100*i)/50 ;j>=0; j--)
        {
            k = n - i - j;
            if(100*i + 50*j + 25*k == c){
                printf("%d:%d,%d,%d\n",cnt , i,j,k);
                cnt ++;
                flag = 1;
            }  
        }
    }
    if(flag == 0)
    {
        printf("Error!\n");
    }
    return 0;
}