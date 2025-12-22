#include <stdio.h>

int main() 
{
	double i;
	char x;
	double y;
	scanf("%c %lf",&x,&i);
	
	if(x == 'F')
	{
		y=(i*9/5)+32;
		printf("The Fahrenheit is %.2f\n",y);
	}
	else if(x == 'C')
	{
		y = (i-32)*5/9;
		printf("The Centigrade is %.2f\n",y);
	}
	return 0;
}
