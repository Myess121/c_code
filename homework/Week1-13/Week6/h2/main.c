#include <stdio.h>

int main(int argc, char** argv) {
	int m,n,s=0;
	scanf("%d",&n);
	for(m=0 ; s<n ; m++)
	{
		s = s + m + 1;
	}
	printf("%d\n",m);
	return 0;
}
