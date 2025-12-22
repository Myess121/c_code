#include <stdio.h>
#include <string.h>
int fanzhuan(int *p,int n1);
int jia(int *p1,int n1,int *p2,int n2,int *q);
void print(int *pp,int n);
int  qufan(int *p);
int wei(int *p);

int main()
{
    int n,i,j,a[1520],b[1520],c[1520],t,w1,w2,w3,flag,fl ;
    char x;
    scanf("%d",&n);
    getchar();
    while(n>0){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
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
        fanzhuan(a,w1);
        fanzhuan(b,w2);
        if(t == -1)
        {
            qufan(b);
        }
        fl = jia(a,w1,b,w2,c);
        w3 = wei(c);
        if(w3 == 0)
        {
            printf("0\n");
            continue;
        }
        if(t == 1){
            print(c,w3);
        }else if(t == -1 && fl == 1){
            c[500] = 0;
            w3 = wei(c);
            if(w3 == 0)
            {
                printf("0\n");
                continue;
            }
            print(c,w3);
        }else {
            printf("-");
            qufan(c);
            w3 = wei(c);
            print(c,w3);
        }

        n--;
    }
    return 0;
}
int fanzhuan(int *p,int n1)
{
    int i,t;
    for(i =0;i<n1 / 2;i++ )
    {
        t = p[i];
        p[i] = p[n1-1-i];
        p[n1-1-i] = t;
    }
}
int jia(int *p1,int n1,int *p2,int n2,int *q)
{
    int i,flag = 0;
    for(i = 0 ;i<501;i++)
    {
        q[i] = p1[i] + p2[i] + flag;
        if(q[i]>9)
        {
            q[i] %= 10;
            flag = 1;
        }else{
            flag = 0;
        }
    }
    if(q[500] == 1){
        return 1;
    }else{
        return 0;
    }
}
void print(int *pp,int n)
{
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d",pp[n-i-1]);
    }
    printf("\n");
}
int  qufan(int *p)
{
    int i,flag = 0;
    p[0] -= 1;
    for (i = 0;i<500;i++)
    {
        p[i] = 9-p[i]+flag;
        if(p[i] > 9){
            flag = 1;
            p[i] %= 10;
        }else{
            flag = 0;
        }
    }
}
int wei(int *p)
{
    int i;
    for(i = 500;i>=0;i--)
    {
        if(p[i] != 0){
            return i+1;
        }
    }
    return 0;
}
