#include <stdio.h>
#include <string.h>
int jia(int *a,int w1,int *b,int w2,int *c);
int jian(int *b,int w2);
int wei(int *p);
int main()
{
    int n,i,j,a[520],b[520],c[520],t,w1,w2,w3,flag;
    char x;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    getchar();
    while(n>0){
        i = 0;
        do{
            x = getchar();
            if(x == '+' ){
                t = 1;
                break;
            }
            if(x == '-'){
                t = -1;
                break;
            }
            a[i] = x - '0';
            i ++;
        }while (1);
        w1 = i;
        i = 0;
        do{
            x = getchar();
            if(x == '\n' ){
                break;
            }
            b[i] = x - '0';
            i ++;
        }while (1);
        w2 = i;
        if(t == 1)
        {
            jia(a,w1,b,w2,c);
            w3 = wei(c);
            for(i = w3-1;i>=0;i--)
            {
                printf("%d",c[i]);
            }
            printf("\n");
        }else if(t == -1){
            w2 = jian(b ,w2);
            flag = jia(a,w1,b,w2,c);
            w3 = wei(c);
            if(flag )
            {
                c[w3-1] = 0;
                w3 = wei(c);
                for(i = w3-1;i>=0;i--)//有错
                {
                    printf("%d",c[i]);
                }
            }else{
                printf("-");
                w2 = jian(c,w3);

                for(i = w3-1;i>=0;i--)
                {
                    printf("%d",c[i]);
                }
            }
            printf("\n");
        }
        n--;
    }
    return 0;
}
int jia(int *a,int w1,int *b,int w2,int *c)
{
    int i,j,flag ;
    for(i  = 1;i<=520;i++)
    {
        flag = 0;
        for(i  = 1;i<=520;i++)
        {
            if(w2-i >=0 && w1-i >= 0){
                c[i-1] = a[w1-i] + b[w2-i] + flag;
                if(c[i-1]>9){
                    c[i-1] %= 10;
                    flag = 1;
                }else{
                    flag = 0;
                }
            }else if(w1-i <0 && w2-i <0){
                break;
            }else if(w1-i <0){
                c[i-1] =b[w2-i] + flag;
                if(c[i-1]>9){
                    c[i-1] %= 10;
                    flag = 1;
                }else{
                    flag = 0;
                }
            }else if(w2-i <0){
                c[i-1] =a[w1-i] + flag;
                if(c[i-1]>9){
                    c[i-1] %= 10;
                    flag = 1;
                }else{
                    flag = 0;
                }
            }
        }
        c[i-1] = flag;
        return flag;
    }
}
int jian(int *b,int w2)
{
    int i,flag = 0;
    b[w2-1] -= 1;
    for(i = w2-1;i>=0;i--)
    {
        b[i]= 9-b[i]+flag;
        if(b[i]>9){
            b[i]%=10;
            flag = 1;
        }else{
            flag = 0;
        }
    }
    return wei(b);
}
int wei(int *p)
{
    int i;
    for(i = 510;i>=0;i--)
    {
        if(p[i] != 0){
            return i+1;
        }
    }
}