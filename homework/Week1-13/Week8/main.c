#include <stdio.h>

int main(int argc, char** argv) {
	int n;
	int i,j,a=1;
	scanf("%d",&n);
	
	for(i = 0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a<10)
			{
				printf("  %d",a);
			 } else if(a<100){
			 	printf(" %d",a);
			 }else {
			 	printf("%d",a);
			 }
			
			a++;
		}
		printf("\n");
	}

	return 0;
}
