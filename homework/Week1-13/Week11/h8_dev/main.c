#include <stdio.h>

int search(int p[12][12],int p1[12][12],int x);
int bian(int q[12][12],int q1[12][12],int i,int j);
int chushi(int arr[12][12],int n);
int main()
{
    int i,a1[12][12],b1[12][12],j,a2[12][12],b2[12][12],m = 100,x,y;
    chushi(a1,0);
    chushi(b1,0);
    chushi(a2,100);
    chushi(b2,100);
    for(i=1;i<11;i++)
    {
        for(j = 1;j<11;j++)
        {
            scanf("%d",&a1[i][j]);       
        }
    }
    for(i=1;i<11;i++)
    {
        for(j = 1;j<1;j++)
        {
            scanf("%d",&b1[i][j]);       
        }
    }
    search (a1,a2,7);
    search(b1,b2,223);
    for(i=1;i<11;i++)
    {
        for(j = 1;j<11;j++)
        {
            if(a1[i][j] == 2){
                if(m > a2[i][j] + b2[i][j]){
                    m  =  a2[i][j] + b2[i][j];
                    x = i;
                    y = j;
                }
            }       
        }
    }
    printf("%d,%d",x,y);



    return 0;
}
int search(int p[12][12],int p1[12][12],int x)//x = 233/7
{
    int i,j,k;
    for(k = 0;k<50;k++)
    {
        for(i = 1;i<11;i++)
        {
            for(j = 1;j<11;j++)
            {
                if(p[i][j] ==0){
                }else if(p[i][j] == x && p1[i][j] != 0){
                    p1[i][j] = 0;
                    bian(p,p1,i,j);
                }else if(p1[i][j] == 100){
                }else if(p[i][j] == 1){
                    bian(p,p1,i,j);
                }
            }
        }
    }
}
int bian(int q[12][12],int q1[12][12],int i,int j)
{
    if(q1[i][j+1] > q1[i][j]+1 && q[i][j+1] !=0)
    {
        q1[i][j+1] = q1[i][j]+1;
    }
    if(q1[i][j-1] > q1[i][j]+1 && q[i][j-1] !=0)
    {
        q1[i][j-1] = q1[i][j]+1;
    }
    if(q1[i+1][j] > q1[i][j]+1 && q[i+1][j] !=0)
    {
        q1[i+1][j] = q1[i][j]+1;
    }
    if(q1[i-1][j] > q1[i][j]+1 && q[i-1][j] !=0)
    {
        q1[i+1][j] = q1[i][j]+1;
    }

}
int chushi(int arr[12][12],int n)
{
    int i,j;
    for(i=0;i<12;i++)
    {
        for(j = 0;j<12;j++)
        {
            arr[i][j] = n;       
        }
    }
}
