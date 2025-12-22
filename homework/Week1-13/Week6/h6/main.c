
#include <stdio.h>
int jue(int a)
{
	if(a<0){
		a= -a;
	}
	return a;
}
int main(int argc, char** argv) {
	int a,b,c,d;
	int x,y,z;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	x = a*d + b*c;
	y = b*d;
	if(x == 0){
		printf("0\n");
	}else{
		while(1)
		{
			z = x % y ;
			if(z == 0){
				break;
			}
			x = y;
			y = z;		
		}
		x = (a*d + b*c) / y;
		y = (b*d) / y;
		
		if(x*y <0){
			printf("-");
		}
		x=jue(x);
		y=jue(y);
		if(y==1){
			printf("%d\n",x);
		}else{
			printf("%d/%d\n",x,y);
		}
	}
	return 0;
}
