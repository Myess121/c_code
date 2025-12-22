#include <stdio.h>

int main(int argc, char** argv) {
	int n;
	int i,j,flag;
	scanf("%d",&n);
	for(i = 2;;i++)
	{
		flag = 0;
		for (j = 2;j<i;j++)
		{
			if(i%j == 0){
				flag = 1;
				break;
			}
		}
		if(i == 2){
			flag = 0;
		}
		if(flag == 0){
			while(n % i == 0)
			{
				printf("%d\n",i);
				n = n / i ;
			}
			if(n==1){
				return 0;
			}
		}
	}

	return 0;
}
