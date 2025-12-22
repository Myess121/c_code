#include <stdio.h>

int main(int argc, char** argv) {
	int n,cnt,yu;
	unsigned int x;
	scanf("%d",&n);
	x = (unsigned int)n;
	for(cnt = 0;x != 0;)
	{
		yu = x % 2;
		if(yu == 1)
		{
			cnt ++;
		}
		x = x / 2;
	}
	printf("%d\n",cnt);
	return 0;
}
