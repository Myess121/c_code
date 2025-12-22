#include <stdio.h>


int main()
{
	long long n,tt,t = 1,t1,sum,g;
	int i,j;
	int x[15]={0};
	scanf("%lld",&n);
	for (i=1;i<n;i++)
	{
		t *= 10;
	}
	t1 = t;
	for(;t<10*t1;t++)
	{
		if(t>7&&((t%10!=5)&&(t%10!=6)))
		{
			continue;
		}
		tt = t;
		for(j = 0;j<n;j++)
		{
			
			x[j] = tt%10;
			tt /= 10;

		}
		sum = 0;
		g=t;
		for (i=0;i<n;i++)
		{
			sum = sum + x[i] * g;
			g = g % (t1) *10;
		}
		if(sum%(t1*10)==t)
		{
			printf("%lld\n",t);
		}
	}
}

/*int main(int argc, char** argv) {
	long long t,t1,g;
	int n,x[14]={0};
	scanf("%d",n);
	for(cnt = 1;c <=n;cnt ++)
	for(j = 1;j<=9 ; j++)
	{
		sum = 0
		t = 1;
		for(l=0;l<c;l++)
		{
			x1 = x[l] * t;
			t *= 10;
		}
		
		for(i = 0;i<c-1;i++)//t =  10^k
		{
			sum = x1*x[i] / t % 10 + sum;
			t /= 10;
			x1 = x%t;
		}
		sum %= 10;
		if(sum == j)
		{
			x[j-1] = j;
		}
	}
	
	
	
	printf("Hello world!\n");
	return 0;
}
*/
