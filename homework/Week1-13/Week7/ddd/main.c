#include <stdio.h>
#include <math.h>
long long zi(int n,long long a);
int main(int argc, char** argv) {
	int n,i,j;
	long long a,b,c; 
	scanf("%d",&n);
	if(n == 1)
	{
		printf("1\n");
	}
	a = zi(n,5);
	b = zi(n,6);
	if(a<b)
	{
		c = b;
		b = a;
		a = c;
	}
	if(b == 0){
		printf("%lld\n",a);
	}else{
		printf("%lld\n%lld\n",b , a);
	}
	return 0;
}
long long zi(int n,long long a)
{
	__uint128_t x;
	long long a1,h = 10;
	int i,j,flag;
	for(i = 1;i<n;i++)
	{
		flag = 1;
		for(j=1;j<=10;j++)
		{
			if (j == 10){
				flag = 0;
				break;
			} 
			a1 = a + h*j;
			x = (__uint128_t)a1*(__uint128_t)a1;
			if(x%(10*(__uint128_t)h) == a1)
			{
				a = a1;
				break;
			 } 
		}
		h *= 10;
	}
	if (flag == 0)
	{
		return 0;
	}else{
		return a;
	}
 } 

