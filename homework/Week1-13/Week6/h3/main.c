#include <stdio.h>

int main(int argc, char** argv) {
	char i;
	int a=1;
	int t=0;
	scanf("%c",&i);
	if(i>=97)
	{
		t = 32;
	}
	
	for(;a<=26 ;i++)
	{
		if(i>90+t)
		{
			i = 65+t;
		}
		printf("%c",i);
		a++;
	}
	printf("\n");
	return 0;
}
