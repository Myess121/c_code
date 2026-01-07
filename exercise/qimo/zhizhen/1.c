#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i,n,*p;
    double max , min , average;
    scanf("%d",&n);
    p = malloc(n*sizeof(int));
    for(i = 0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    max = p[0];
    min = p[0];
    average = 0;
    for(i = 0;i<n;i++)
    {
        if((double)p[i] > max)
        {
            max = (double)p[i];
        }
        if((double)p[i] < min)
        {
            min = (double)p[i];
        }
        average += (double)p[i];
    }
    average /= n;
    printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf\n",average,max,min);

    return 0;
}