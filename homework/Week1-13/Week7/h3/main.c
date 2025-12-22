#include <stdio.h>

int main(int argc, char** argv) {
	int a,b,c,d,mon;
	int i,j,k,m,cnt=0;
	scanf("%d,%d,%d,%d",&a,&b,&c,&d);
	scanf("%d",&mon);
	for(i = 1 ; i<=mon / (a+b+c+d) ; i++)
	{
		for(j = i;j<=mon / b; j++)
		{
			for(k = j ;k<=mon / c;k++)
			{
				for(m = k ; m<=mon / d ; m++)
				{
					if(a*i + b*j + c*k + d*m == mon)
					{
						printf("%d,%d,%d,%d\n",i,j,k,m);
						cnt ++;
					}
				}
			}
		}
	}
	return 0;
}
