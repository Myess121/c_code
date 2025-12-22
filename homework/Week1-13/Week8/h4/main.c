#include <stdio.h>

int main(int argc, char** argv) {
	int n,i,j;
	char x;
	scanf("%d %c",&n,&x);
	if(x>'Z'||x<'A')
	{
		printf("input error.\n");
		return 0;
	}
	x = x + n - 1;
	for(;x>'Z';)
	{
		x -= 26;
	}
	for (i=0;i<n-1;i++)
	{
		for(j = 0;j<i;j++)
		{
			printf(" ");
		}
		
		printf("%c",x);
		for(j = 0;j<2*n-2*i-3;j++)
		{
			printf(" ");
		}
		printf("%c",x);
		x --;
		if(x<'A')
		{
			x = 'Z';
		}
		printf("\n");
	}
	for(j = 0;j<n-1;j++)
		{
			printf(" ");
		}
	printf("%c\n",x);
	for (i = 0;i<n-1;i++)
	{
		x --;
		if(x<'A')
		{
			x = 'Z';
		}
		for(j = 0;j<n-2-i;j++)
		{
			printf(" ");
		}
		
		printf("%c",x);
		for(j = 0;j<2*i + 1;j++)
		{
			printf(" ");
		}
		printf("%c",x);
		printf("\n");
	}
	return 0;
}
