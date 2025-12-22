#include <stdio.h>
long long cheng(int n,long long a[])
{
	int i;
	long long x=1;
	for(i=0;i<n;i++)
	{
		x *= a[i];
	}
	return x;
}

long long gong(long long x,long long y)
{
	long long z;
	while(1)
	{
		z = x % y ;
		if(z == 0){
			break;
		}
		x = y;
		y = z;		
	}
	return y;
}

long long jue(long long x)
{
	if(x<0){
		x = -x;
	}
	return x;
}

int main(int argc, char** argv) {
	long long a[19]={0};
	long long b[19]={0};
	int n,i;
	long long a1,b1,g;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&a[i],&b[i]);
	}
	a1 = cheng(n,a);
	b1 = cheng(n,b);
	
	if(a1==0){
		printf("0\n");
	}else {
		g = gong(a1,b1);
		a1 /= g;
		b1 /= g;
		if(a1*b1 < 0){
			printf("-");
		}
		a1 = jue(a1);
		b1 = jue(b1);
		if(b1 == 1){
			printf("%lld\n",a1);
		}else{
			printf("%lld/%lld\n",a1,b1);
		}		
	}
	return 0;
}
