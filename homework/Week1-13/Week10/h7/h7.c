#include <stdio.h>

int main()
{
    int a,b,i;
    long long x[2]={1,0},y[2]={1,0},z[2]={1,0};
    scanf("%d %d",&a,&b);
    for(i=0;i<b-a-1;i++)
    {
        z[0] = x[0]+ y[0];
        z[1] = x[1]+ y[1];
        if(z[0]>=1000000000000000000)
        {
            z[1] = z[1] + z[0]/1000000000000000000;
            z[0] = z[0]%1000000000000000000;
        }
        y[0] = x[0];
        y[1] = x[1];
        x[0] = z[0];
        x[1] = z[1];
    }
    if(z[1] == 0){
        printf("%lld\n",z[0]);
    }else{
        printf("%lld%lld\n",z[1],z[0]);
    }
    return 0;
}