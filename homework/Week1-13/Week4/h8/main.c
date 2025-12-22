#include <stdio.h>
int main()
{
	long long M, K, N;
	scanf("%lld %lld", &N, &M);
	K = N / (N / M) - N / (N / M + 1);
	printf("%lld\n", K);
	return 0;
}


/*int main(int argc, char** argv) {
	long long M,K = 0,N;
	long long y,i,t=0;
	scanf("%lld %lld",&N,&M);
	y = N / M;
	t=N;
	for (i=1;t>=y;i++)
	{
		t = N/i;
		if(t == y)
		{
			K++;
		}
	}
	printf("%lld\n",K);
	return 0;
}*/
