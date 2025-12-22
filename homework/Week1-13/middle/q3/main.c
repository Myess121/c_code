#include <stdio.h>
void f(int n,char m,char p);
int main(int argc, char** argv) {
	int n,i;
	char x;
	scanf("%c %d",&x,&n);
	for(i=0;i<n;i++)
	{
		printf("%c ",x);
	}
	printf("\n");
	if(n == 1)
	{
		return 0;
	}
	if((int)x%2 == 1){
		f(n,' ',x);
	}else{
		f(n,x,' ');
	}
	for(i=0;i<n;i++)
	{
		printf("%c ",x);
	}
	printf("\n");
	return 0;
}
void f(int n,char m,char p)
{
	int i,j;
	for(i = 0;i<n-2;i++)
	{
		printf("%c ",m);
		for(j=0;j<n-2;j++)
		{
			printf("  ");
		}
		printf("%c ",p);
		printf("\n");
	}
}

