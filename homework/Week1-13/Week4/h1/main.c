#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) 
{
	int a,b,c;
	double t,x1,x2,t1,x;
	scanf("%d %d %d",&a ,&b, &c);
	if(a==0)
	{
		if(b==0)
		{
			printf("Input error!\n");
		}
		else
		{
			x = -c/(double)b;
			if(x==0){
				x=0;
			}
			printf("x=%.6f\n",x);	
		}
	}else
	{
		t = b*b - 4*a*c;
		x = -(double)b / 2 / a;
		if(x==0){
				x=0;
		}
		if(t<0)
		{
			t1 = sqrt(-t) / 2 / a;
			if(x==0)
			{
				printf("x1=%.6fi\nx2=-%.6fi\n",t1,t1);	
			}else{
				printf("x1=%.6f+%.6fi\nx2=%.6f-%.6fi\n",x,t1,x,t1);
			}
				
		}else if(t==0){
			printf("x1=x2=%.6f\n",x);
		}else {
			t1 = sqrt(t) /2 /a;
			x1 = x + t1;
			x2 = x - t1;
			printf("x1=%.6f\nx2=%.6f\n",x1,x2);
			
		}	
	}
	return 0;
}
