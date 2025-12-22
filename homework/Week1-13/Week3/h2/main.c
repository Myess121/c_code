#include <stdio.h>

int f(int x1, int z1) ;

int main() 
{
	int year;
	int cnt = 0;
	int i;
	int t;
	scanf("%d",&year);
	for (i=1; cnt<2; i++)
	{
		t = f(year,i);
		if (t == 0)
		{
			cnt++;
		}
	}
	
	printf("%d年的母亲节是5月%d日。\n",year,i-1);
	return 0;
}
int f(int x1, int z1) 
{
	int y1 = 5;
	int x=1900;
	int t;
	int day=120;
	int i;
	int mon[12]={31,28,31,30,31};

	day = day + z1;   //这个月过的天数 	
	day = day + (x1-x)*365;  //1900年到去一年的不算润的那几天的基础总天数 
	day = day + (x1-x)/4 + 1;  //闰年 
	day = day - (x1-1800)/100;  //100的倍数不闰年 
	day = day + (x1-1600)/400;  //400的倍数是闰年 
	
	if(x1%4 == 0 && y1<=2 && (x1-x)%100 != 0)  //在闰年但没影响时 
	{
		day= day-1;
	}
	t= (day)%7;  //1900.1.1是周一 
	
	return t;
}
