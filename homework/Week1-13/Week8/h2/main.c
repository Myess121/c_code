#include <stdio.h>

int main(int argc, char** argv) {
	int n;
	int i,j;
	scanf("%d",&n);
	for(i= 0;i<2*n-1;i++)
	{
		printf("*");
	}
	printf("\n");
	for(i = 1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			printf(" ");
		}
		printf("*");
		if(i==n-1)
		{
			printf("\n");
			break;
		}else{
			for(j=0;j<2*n-2*i-3;j++)
			{
				printf(" ");
			}
			printf("*\n");
		}
		
		
	}
	
	return 0;
}
