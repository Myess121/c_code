#include <stdio.h>
#include <string.h>
int putq(int x,int y,int n);
int change(int x,int y,int n,int t);
int a[10][10],b[10][10],cnt = 0,flag = 0;
int main()
{
    int n,i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        putq(0,i,n);
    }
    printf("%d\n",cnt);
    return 0;
}
int putq(int x,int y,int n)
{
    int i;
    if(b[x][y] !=0){
        return 0;
    }
    if(x+1 == n){
        cnt++; 
        return 0;
    }
    change(x,y,n,1);
    flag = 1;
    for(i = 0;i<n;i++)
    {
        putq(x+1,i,n);
    }
    change(x,y,n,-1);
    flag = 1;
}

int change(int x,int y,int n,int t)
{
    int i;
    for(i = 0;i<n;i++)
    {
        b[x][i] +=t;
        b[i][y] +=t;
    }
    b[x][y] -t;
    for(i = 1;x-i>=0 && y+i<n;i++)
    {
        b[x-i][y+i] +=t;
    }
    for(i = 1;x+i<n && y+i<n;i++)
    {
        b[x+i][y+i] +=t;
    }
    for(i = 1;x+i<n && y-i>=0;i++)
    {
        b[x+i][y-i] +=t;
    }
    for(i = 1;x-i>=0 && y-i>=0;i++)
    {
        b[x-i][y-i] +=t;
    }
}