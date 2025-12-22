#include <stdio.h>

int main(int argc, char** argv) {
	int a,b,i;
	int cnt=0;
	scanf("%d %d",&a,&b);
	for(i = a; i<=b; i++)
	{
		cnt += i ;
	}
	printf("The sum from %d to %d is %d.\n",a,b,cnt);
	
	return 0;
}
