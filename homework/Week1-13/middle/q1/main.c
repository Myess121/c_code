#include <stdio.h>

int main(int argc, char** argv) {
	int n,i,j,k;
	char x;
	scanf("%c %d",&x,&n);
	for(k = 0;k<(n+1)/2;k++)
	{
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<i;j++)
			{
				printf(" ");
			}
			printf("%c\n",x);
		}
		if(k == (n-1)/2&& n%2 == 1)
		{
			return 0;
		}
		for(i = 0;i<n;i++)
		{
			for(j = 0;j<n-1-i;j++)
			{
				printf(" ");
			}
			printf("%c\n",x);
		}
	}
	return 0;
}
