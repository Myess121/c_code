#include <stdio.h>
int main ()
{
    int week,d,m,y,d1 = 1,m1 = 1,y1 = 1900,mon[13] = {0 ,31, 28,31,30,31,30,31,31,30,31,30,31},i,cnt = 0;
    scanf("%d %d %d",&y,&m,&d);
    for(i = 1900;i<y;i++)
    {
        cnt += 365;
        if((i%4 ==0&&i%100 != 0)||i %400 == 0){
            cnt ++;
        } 
    }
    for(i = 1;i<m;i++)
    {
        if(i == 2){
            if((y%4 ==0&&y%100 != 0)||y %400 == 0){
                cnt ++;
            }  
        }
        cnt += mon[i];
    }
    cnt += d;
    week = (cnt) % 7;
    printf("%d\n",week);
    return 0;
}