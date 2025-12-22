#include <stdio.h>
#include <string.h>
int fanzhuan(int p[520],int n1);
int jia(int p1[520],int n1,int p2[520],int n2,int q[520],int t);
int wei(int p[520]);
int print(int pp[520],int n);
int main()
{
    int n,i,j,a[520],b[520],c[520],t,w1,w2,w3,flag,fl ;
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
        fl = jia(a,w1,b,w2,c,t);
        if(t == 1){
            w3 = wei(c);
            print(c,w3);
        }else if(t == -1){
            if(fl == 1){
                jia(b,w2,a,w1,c,t);
                w3 = wei(c);
                printf("-");
                print(c,w3);
            }else{
                w3 = wei(c);
                print(c,w3);
            }
        }
        n--;
    }

    return 0;
}
int fanzhuan(int p[520],int n1)
{
    int i,t;
    for(i =0;i<n1 / 2;i++ )
    {
        t = p[i];
        p[i] = p[n1-1-i];
        p[n1-1-i] = t;
    }
    return 0;
}
int jia(int p1[520],int n1,int p2[520],int n2,int q[520],int t)
{
    int i,flag = 0;
    for(i = 0 ;i<501;i++)
    {
        q[i] = p1[i] + t*p2[i] + t*flag;
        if(q[i]>9)
        {
            q[i] %= 10;
            flag = 1;
        }else if(q[i]<0){
            q[i] = 10 + q[i];
            flag = 1;
        }else{
            flag = 0;
        }
    }
    if(q[500] == 1||q[500] == 9){
        return 1;
    }else{
        return 0;
    }
}
int print(int pp[520],int n)
{
    if(n == 0){
        printf("0\n");
        return 0;
    }
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d",pp[n-i-1]);
    }
    printf("\n");
}
int wei(int p[520])
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