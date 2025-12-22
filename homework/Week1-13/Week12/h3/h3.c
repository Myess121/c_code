#include <stdio.h>
#include <math.h>
double s(double x,double p,double e);

int main()
{
    double x,e,p;
    scanf("%lf %le",&x,&e);
    p = s(x,x,e);
    printf("%.8lf\n",p);
    return 0;
}

double s(double x,double p,double e)
{
    if(fabs(p*p-x)<e)
    {
        return p;
    }
    return s(x,(p + x / p)/2,e);
}
/*
int main()
{
    double x,e,p;
    scanf("%lf %le",&x,&e);
    while(fabs(p*p-x)>=e)
    {
        p = (p + x / p)/2;
    }
    printf("%.8lf\n",p);
    return 0;
}*/