#include <stdio.h>
long long jue(long long x)
{
	if(x<0){
		x = -x;
	}
	return x;
}
__uint128_t gong(__uint128_t x,__uint128_t y)
{
	__uint128_t z;
	while(1)
	{
		z = x % y ;
		if(z == 0){
			break;
		}
		x = y;
		y = z;		
	}
	return jue(y);
}

int main(int argc, char** argv) {
	long long a[19]={0};
	long long b[19]={0};
	int n,i,t = 1;
	__uint128_t a1=1,b1=1,g;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld %lld",&a[i],&b[i]);
		
		if(a[i]==0 || t==0){
			t = 0;
		}else {
			if(a[i]*b[i]<0)
			{
				t = t * -1;
			}
			a1 = a1 * jue(a[i]);
			b1 = b1 * jue(b[i]);
			g = gong(a1,b1);
			a1 /= g;
			b1 /= g;
		}
	}
	if(t == 0){
		printf("0\n");
	}else{
		if(t < 0){
		printf("-");
		}
		if(b1 == 1){
			printf("%lld\n", (long long)a1);
		}else{
			printf("%lld/%lld\n",(long long)a1,(long long)b1);
		}	
	} 	
	
	return 0;
}
