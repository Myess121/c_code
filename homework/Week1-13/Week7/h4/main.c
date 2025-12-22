#include <stdio.h>

int main(int argc, char** argv) {
	int n,m,x,d;
	scanf("%d %d %d",&n,&m,&x);
	for(d=0; ; n--)
	{
		d++;
		x = x - n;
		if(x<=0)
		{
			printf("青蛙能爬出井，且第 %d 天爬出井。\n",d);
			break;
		}
		x = x + m;
		if(n<=m)
		{
			printf("青蛙不能爬出井。\n");
			break;
		}
	}
	return 0;
}
