#include <stdio.h>
#include <string.h>
int n,arr[100][6],a[300][4],xmax,xmin,ymax,ymin;
int ffun(int i,int j,int x,int y,int z);
int fun1(int a,int b,int i);
double s;
long long cnt = 0;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {                              //x1          y1             x2          y2      x3     y3
        scanf("%d %d %d %d %d %d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3],&arr[i][4],&arr[i][5]);
        
        ffun(i,0,0,1,2);
        ffun(i,1,1,2,0);
        ffun(i,2,2,0,1);
    }
    xmax = arr[0][0];
    xmin = arr[0][0];
    ymax = arr[0][1];
    ymin = arr[0][1];
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<3;j++)
        {
            if(arr[i][2*j]>xmax){
                xmax = arr[i][2*j];
            }else if(arr[i][2*j]<xmin)
            {
                xmin = arr[i][2*j];
            }
            if(arr[i][2*j+1]>ymax){
                ymax = arr[i][2*j+1];
            }else if(arr[i][2*j+1]<ymin)
            {
                ymin = arr[i][2*j+1];
            }
        }
    }
    for(i = (xmin*100);i<=(xmax*100);i++)//10000*
    {
        for(j = (ymin*100);j<=(ymax*100);j++)
        {
            for(k = 0;k<n;k++)
            {
                if(fun1(i,j,k)){
                    cnt++;
                    break;
                }
            }
        }
    }
    s = (double)(cnt) / 10000;
    printf("%.2lf\n",s);
    return 0;
}
int ffun(int i,int j,int x,int y,int z)
{
    a[3*i+j][0] = arr[i][2*x+1] - arr[i][2*y+1];//y1-y2
    a[3*i+j][1] = arr[i][2*y] - arr[i][2*x];//x2-x1
    a[3*i+j][2] = arr[i][2*x]*arr[i][2*y+1] - arr[i][2*y]*arr[i][2*x+1];//x1y2-x2y1
    if(a[3*i+j][0]*arr[i][2*z] + a[3*i+j][1]*arr[i][2*z+1] + a[3*i+j][2] >0)
    {
        a[3*i+j][3] = 1;
    }else{
        a[3*i+j][3] = -1;
    }
}
int fun1(int x,int b,int i)
{
    int j;
    double a1 = x/100.0,b1 = b/100.0;
    for(j = 0;j<3;j++)
    {
        if(((double)a[3*i+j][0] *a1 + (double)a[3*i+j][1]*b1 + (double)a[3*i+j][2])*(double)a[3*i+j][3]<0)
        {
            return 0;
        }
    }
    return 1;
}
    