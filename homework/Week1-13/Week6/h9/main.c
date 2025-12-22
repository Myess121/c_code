#include <stdio.h>

int main(int argc, char** argv) {
	long long n;
	int i;
	scanf("%lld",&n);
	for(i=0;i<20;i++)
	{
		if(n % 2 == 1){
			printf("%lld*3+1=%lld\n",n,3*n + 1);
			n = 3*n + 1;
		}else{
			printf("%lld/2=%lld\n",n,n/2);
			n = n / 2;
			if(n == 1)
			{
				break;
			}
		}
	
	}

	return 0;
}
