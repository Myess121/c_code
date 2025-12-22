#include <stdio.h>
#include <string.h>
int search(int *p, int n, int des);
int search_h(int *p, int n);
int fun1(int *p,int n);
int fun2(int *p,int n);
void shuchu(int t);
int main()
{
    int a[4][16],n[4],i,j,flag,flag2,y;
    char x;
    while(1)
    {
        flag = 0;
        flag2 = 0;
        memset(a,0,sizeof(a));
        for(i = 0;i<4;i++)
        {
            scanf("%d",&n[i]);
            getchar();
            for(j = 0;j<n[i];j++)
            {
                do{
                     x = getchar();
                }
                while(x == ' ');
                if(x == 'H'){
                    scanf("%d",&a[i][j]);
                }else {
                    if(x == 'S'){
                        a[i][j] = 14; 
                    }else if(x == 'D'){
                        a[i][j] = 15; 
                    }else if(x == 'C'){
                        a[i][j] = 16; 
                    }
                    getchar(); 
                    getchar(); 
                }
                getchar(); 
            }          
        }
        if(n[0]+n[1]+n[2]+n[3] == 0)
            {
                return 0;
            }
        for(i = 0;i<4;i++)
        {
                flag = flag + search_h(a[i],n[i]);//看有没有人有全部H
        }
        if(flag > 0)//在一个人手里
        {
            for(i = 0;i<4;i++)
            {
                if(flag2 > 0){
                    printf(" ");
                }
                shuchu(fun1(a[i],n[i]));
                flag2 ++;
            }
        }else{
            for(i = 0;i<4;i++)//不在一个人手里
            {
                if(flag2 > 0){
                    printf(" ");
                }
                shuchu(fun2(a[i],n[i]));
                flag2 ++;
            }
        }
        printf("\n");       
    }
    return 0;
}

int search(int *p, int n, int des)
{
    int i;
    for(i = 0;i<n;i++)
    {
        if(*(p+i) == des){
            return 1;
        }
    }
    return 0;
}
int search_h(int *p, int n)
{
    int i,s = 0;
    if(n<13){
        return 0;
    }
    for(i = 1;i<14;i++)
    {
        s = s + search(p,n,i);
    }
    if(s == 13){
        return 1;
    }else{
        return 0;
    }
}
int fun1(int *p,int n)
{
    if(search_h(p,n) == 1)
    {
        if(search(p,n,14) == 1 && search(p,n,15) == 1){
            return 500 + 500 * search(p,n,16);
        }else {
            return (200 + 100*(search(p,n,15) - search(p,n,14))) * (1 + search(p,n,16));
        }
    }else if(search(p,n,16) == 1){
        if(search(p,n,14) == 0 && search(p,n,15) == 0){
            return 50;
        }else{
            return 200*(search(p,n,15) - search(p,n,14));
        }
    }else {
        return 100*(search(p,n,15) - search(p,n,14));
    }
}
int fun2(int *p,int n)
{
    int sum = 0,i;
    int q[14] = {0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};
    for(i = 1;i<14;i++)
    {
        sum = sum + search(p,n,i)*q[i];
    }
    sum = sum + 100*(search(p,n,15) - search(p,n,14));
    if(search(p,n,16) == 1 && n == 1)
    {
        return 50;
    }else{
        return sum * (1 + search(p,n,16));
    }
}
void shuchu(int t)
{
    if(t == 0){
        printf("0");
    }else{
        printf("%+d",t);
    }
}