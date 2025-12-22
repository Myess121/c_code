#include <stdio.h>

int main(int argc, char** argv) 
{
	long long x,y,min,t;
	long long b,a;
	scanf("%d*%d %d",&x,&y,&min);
	t = 60* min;
	b = x * y * 24 * 30 / 8;
	a = b * t/ 1024;
	 
	printf("%lld\n",a);
	return 0;
}
