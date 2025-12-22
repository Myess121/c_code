#include <stdio.h>

int main(int argc, char** argv) {
	int n,i,sum=1;
	scanf("%d",&n);
	for (i=n-1;i>=1;i--)
	{
		sum = 2*i +2*sum; 
	}
	if(sum == 1)
	{
		printf("The monkey got %d peach in the first day.\n",sum);
	}else{
	printf("The monkey got %d peaches in the first day.\n",sum);		
	}

	return 0;
}
