#include <stdio.h>

int main(int argc, char** argv) {
	double a,b,x,y;
	scanf("%lf %lf %lf %lf",&a ,&b ,&x ,&y);
	if(x*x/a + y*y/b != 1)
	{
		printf("Input error!\n");
	}else if(x==0){
		printf("y=%.6f\n",b/y);
	}else if(y==0){
		printf("x=%.6f\n",a/x);
	}else{
		printf("y=%.6fx%+.6f\n",-x*b/y/a,b/y);
	}
	return 0;
}
