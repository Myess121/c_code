#include <stdio.h>

int main(){
    int cnt = 0,y,m,d,mon[12]={31,28,31,30,31,30,31,31,30,31,30,31},y1 = 2012,m1 = 4,d1 = 8;
    int a[5]={38,49,50,16,27},n,flag;
    scanf("%d %d %d",&y,&m,&d);
    if(y == y1 && m == m1){
        cnt = d-d1;
    }else {
        cnt = 30-d1;
        cnt += d;
        m1++;
    }
    while(y1<y||(y == y1 && m1<m))
    {
        
        
        if(((y1%4==0 && y1%100!=0) || y1%400==0)&& m1 == 2)
            {
                cnt ++;
            }
        cnt += mon[m1-1];
        m1++;
        if(m1>12){
            m1 = 1;
            y1++;
        }
    }
    n = cnt / (13*7);
    cnt %= (13*7);
    cnt %= 7;
    n = n%5;
    if(cnt == 6||cnt ==0){
        printf("Free.\n");
        return 0;
    }else{
        flag = cnt-1-n;
        while(flag<0){
            flag+=5;
        }
        printf("%d and %d.\n",a[flag]/10,a[flag]%10);
        return 0;
    }
    

    return 0;
}