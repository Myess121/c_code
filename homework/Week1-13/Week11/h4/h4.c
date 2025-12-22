#include <stdio.h>
int leap_year( int );	
int year_days( int );	
int days(int,int,int);	

int leap_year( int year )	// 判断闰年或平年
{	return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}

int year_days(int year)		// 计算一整年的天数
{	return leap_year( year ) ? 366 : 365;
}

int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天
{	int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;
	
	if  ( leap_year( year ) && month >2 )
		day++;
	
	for ( i=1; i<month; i++ )
		day += months[i];

	return day;
}

int main()
{
    int d ,m ,y,d1,m1,y1,i,cnt = 0;
    scanf("%d %d %d",&y,&m,&d);
    scanf("%d %d %d",&y1,&m1,&d1);
    for(i = y+1;i<y1;i++)
    {
        cnt = cnt + year_days(i);
    }
    cnt = cnt + days(y1,m1,d1);
    if(y == y1){
        cnt = cnt - days(y,m,d);
    }else{
        cnt = cnt + year_days(y) - days(y,m,d);
    }
    printf("%d days\n",cnt);

  return 0;
} 
