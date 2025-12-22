#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	
	int m=a/100;
	int p=a%10;
	
	printf("%03d\n",a-99*m+99*p);
	
	return 0;
}
