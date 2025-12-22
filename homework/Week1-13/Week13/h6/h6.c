#include <stdio.h>  
#include <string.h>
int main()
{
    int i=0,w,y=-1,n,a[100],flag = 0,fla = 0;
    char x;
    memset (a,0,sizeof(a));
    while(1)
    {
        x = getchar();
        if(x == '-'){
            flag = 1;
            continue;
        }
        if(x == ' '){
            continue;
        }
        if(x == 'e'||x == 'E'){
            break;
        }
        if(x == '.'){
            y = i;
            continue;
        }
        a[i] = x-'0';
        i++;
    }
    if(y == -1){
        y = i;
    }
    w = i;
    scanf("%d",&n);
    y = y + n;
    for(i = 0 ;i < 8 + y;i++){
        if(a[i] != 0){
            fla = 1;
            break;
        }
    }
    if(flag == 1 && fla != 0)
    {
        printf("-");
    }
    if(y<=0){
        y = -y;
        printf("0.");
        for(i = 0;i<y && i<8;i++)
        {
            printf("0");
        }
        for(i = 0;i<8-y;i++)
        {
            printf("%d",a[i]);
        }
    }else {
        for(i = 0;i<y-1 && a[i] == 0;i++){}
        for(;i<y;i++)
        {
            printf("%d",a[i]);
        }
        printf(".");
        for(i= 0;i<8;i++)
        {
            printf("%d",a[i+y]);
        }
    }
    printf("\n");
    return 0;
}