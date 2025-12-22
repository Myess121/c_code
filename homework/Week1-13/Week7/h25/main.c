#include <stdio.h>

int main(int argc, char** argv) {
	int y1,y2,m1,m2,d1,d2;
	int k1,k2,j1,j2,cnt = 0,day = 0;
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d %d",&y1,&m1,&d1);
	scanf("%d %d %d",&y2,&m2,&d2);
	k1 = m1;
	j1 = d1;
	for(;y1<=y2;y1++)
	{
		k2 = 12;
		if(y1==y2){
			k2 = m2;
			cnt ++;
		}
		for(;k1<=k2;k1++)
		{
			j2 = mon[k1 - 1];
			if((((y1%4==0)&&(y1%100!=0))||(y1%400 == 0))&&(k1 == 2)){
				j2 ++;
			}
			if((cnt == 1)&&(k1 == m2)){
				j2 = d2;
			}
			day = day + j2 - j1;
			j1 = 0;
		}
		k1 = 1;
	}
	if(day == 1)
	{
		printf("%d day\n",day);
	 } else{
	 	printf("%d days\n",day);
	 }
	
	return 0;
}
