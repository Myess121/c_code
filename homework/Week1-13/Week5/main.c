#include <stdio.h>

int main(int argc, char** argv) {
	long long  a ;
	long long  d=0,h=0, m=0,s=0;
	scanf("%lld",&a);
	d = a/86400;
	a = a - d*86400;
	h = a/3600;
	a = a - h*3600;
	m = a/60;
	a = a - m*60;
	s = a;
	printf("%lld天%lld小时%lld分%lld秒\n",d,h,m,s);
	return 0;
}
