#include <stdio.h>

int main(int argc, char** argv) 
{
	int x1,y1,z1;
	int x=1900;
	int t;
	int day=0;
	int i;
	scanf("%d %d %d",&x1,&y1,&z1 );
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	for(i=1; i<y1;i++)
	{
		day = day + mon[i-1]; 
	}
	day = day + z1; 
	day = day + (x1-x)*365;  
	day = day + (x1-x)/4 + 1;  
	day = day - (x1-1800)/100; 
	day = day + (x1-1600)/400;  
	
	if(((x1%4 == 0 && x1 % 100 != 0 )||x1%400==0)&&y1<=2)  
	{
		day= day-1;
	}
	t= (day)%7;   
	 
	printf("%d\n",t);
	return 0;
}
