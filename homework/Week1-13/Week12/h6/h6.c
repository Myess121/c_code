#include <stdio.h>
#include <string.h>

int main ()
{
    int a[150],b[150],c[60][150],d[150],i=0,j,w1,w2,y1 = 0,y2 = 0,flag,flag2 = 0,w3 = 0,y0 = 0,y3 = 0,min;
    char x;
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    memset (c,0,sizeof(c));
    memset (d,0,sizeof(d));
    do {
        x = getchar();
        if(x == '-'){
            flag2 ++;
            continue;
        }
        if(x == '.'){
            y1 = i;
            if(i == 0){
                a[0] = 0;
                i ++;
                y1 = 1;
            }
        }else if(x>='0' && x<='9'){
            a[i] = x - '0';
            i++;
        }
    }while(x != '\n');
    if(y1 == 0){
        y1 = i;
    }
    w1 = i;
    i = 0;
    do {
        x = getchar();
        if(x == '-'){
            flag2 ++;
            continue;
        }  
        if(x == '.'){
            y2 = i;
            if(i == 0){
                b[0] = 0;
                i ++;
                y2 = 1;
            }
        }else if(x>='0' && x<='9'){
            b[i] = x - '0';
            i++;
        }
    }while(x != '\n');
    if(y2 == 0){
        y2 = i;
    }
    w2 = i;
    for(i = 0;i<w2;i++)
    {
        flag = 0;
        for(j = 0;j<w1;j++)
        {
            c[i][i+j] = b[w2-1-i] * a[w1-1-j] + flag;
            if(c[i][i+j] > 9)
            {
                flag = c[i][i+j] / 10;
                c[i][i+j] %= 10;
            }else{
                flag = 0;
            }
        }
        if(flag != 0){
            c[i][i+j] = flag;
        }
    }
    flag = 0;
    for(i = 0;i<w1 * w2 + 1;i++)
    {
        
        for(j = 0;j<w2;j++)
        {
            d[i] = c[j][i] + d[i] ;
            
        }
        d[i] += flag;
        if(d[i] > 9)
            {
                flag = d[i] / 10;
                d[i] %= 10;
            }else{
                flag = 0;
        }
    }
    for(i = w1 + w2 +1;i>=0;i--)
    {
        if(d[i] != 0)
        {
            w3 = i;
            break;
        }
    }
    if(w3 <= (w1 - y1)+ (w2 - y2)){
        w3 = (w1 - y1)+ (w2 - y2) ;
    }
    for(i = 0;i<w1*w2 + 1;i++)
    {
        if(d[i] != 0)
        {
            break;
        }else{
            y0 ++;
        }
    }
    y3 = (w1 - y1)+ (w2 - y2);
    min = y3;
    if(y3 > y0){
        min = y0;
    }
    if(w3 == min && d[w3] == 0)
    {
        printf("0\n");
        return 0;
    }
    if(flag2  == 1)
    {
        printf("-");
    }
    for(i = w3;i>=min;i--)
    {
        if(i == y3-1)
        {
            printf(".");
        }
        printf("%d",d[i]);
        
    }
    printf("\n");
}