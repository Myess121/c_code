#include <stdio.h>
#include <string.h>

int main ()
{
    int a[30],b[30],i,n,cnt1 = 0,cnt2 = 0,flag,flag2 = 0;
    char x;
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    getchar();
    do{
        flag = 0;
        for(i = 0;i<n;i++)
        {
            x = getchar();
            if(x == '#' && b[i] == 2){
            }else if(x == '#' && b[i] == 1){
                b[i] = 2;
            }else if(x == '#' && b[i] == 0){
                b[i] = 1;
            }else if(x == '-' && b[i] == 2){
                b[i] = 0;
                cnt1 ++;
            }else if(x == '-' && b[i] == 1){
                b[i] = 0;
                cnt2 ++;
            }
            if(x == '-'){
                flag ++;
            }
        }
        if(flag == n ){
            flag2 ++;
        }else{
            flag2 = 0;
        }
        getchar();
    }while(flag2 != 3);
    printf("%d\n%d\n",cnt2,cnt1);
    return 0;
}