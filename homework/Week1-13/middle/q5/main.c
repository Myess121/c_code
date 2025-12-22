#include <stdio.h>

int main(int argc, char** argv) {
	int n,a=1,i,j;
	char x; 
	scanf("%c",&x);
	if(x<'1'||x>'9'){
		printf("input error\n");
		return 0;
	}
	n = (int)(x-'0');
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<i; j++)
		{
			printf(" ");
		}
		printf("%d",a);
		for(j=0;j<2*n-3-2*i;j++)
		{
			printf(" ");
		}
		printf("%d\n",a);
		a++;
	}
	for(j=0; j<n-1; j++)
		{
			printf(" ");
		}
	printf("%d\n",a);
	for(i = 0;i<n-1;i++)
	{
		a++;
		if(a>9){
			a=1;
		}
		for(j = 0;j<n-i-2;j++)
		{
			printf(" ");
		}
		printf("%d",a);
		for(j = 0;j<2*i +1;j++)
		{
			printf(" ");
		}
		printf("%d\n",a);
		
	}
	return 0;
}
