#include <stdio.h>

int main(int argc, char** argv) {
	int x,y,z;
	int a,b;
	scanf("%d %d",&x,&y);
	a=x;
	b=y;
	
	while(1)
	{
	z = x % y ;
	if(z == 0)
	{
		break;
	}
	x = y;
	y = z;		
	}
	printf("GCD(%d,%d)=%d\n",a,b,y);
	return 0;
}
