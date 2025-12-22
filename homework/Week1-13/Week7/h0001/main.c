#include <stdio.h>

int main(int argc, char** argv) {
	int a,b,h;
	int x = 0,cnt = 0;
	scanf("%d %d",&a,&b);
	for(;a<=b;a++)
	{
		if(a%7==0)
		{
			x ++;
		}else{
			h=a;
			for(;h!=0;)
			{
				if(h%10==7 ||h%10==-7)
				{
					x ++ ;
					break;
				}else{
					h = h / 10;
				}
			}
		}
		if(x != 0)
		{
			cnt ++;
			x = 0;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
