#include <stdio.h>

int main() 
{
	int h,m;
	double a,b,j;
	scanf("%d %d",&h,&m);
	a = (h%12)*360/12;  //小时的基础角度 
	a = a + m*30.0/60;    //小时的精确角度
	b = m*360/60; 
	j = a - b;
	if(j<0)
	{
		j = -j;
		
	}
	if(j>180)
	{
		j = j-180;
	}
	printf("At %d:%02d the angle is %.1f degrees.\n",h,m,j);
	return 0;
}
