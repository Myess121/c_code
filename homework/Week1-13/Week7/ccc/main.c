#include <stdio.h>
void print(int n,int a[]) ;
int main(int argc, char** argv) {
	int a[15] = {5,2,6,0,9,8,2,1,2,8,1,9,9,5,2};
	int b[15] = {6,7,3,9,0,1,7,8,7,1,8,0,0,4,7};
	int n,i;
	scanf("%d",&n);
	if(n == 1)
	{
		printf("1\n");
	 } 
	if(a[n-1] == 0)
	{
		print(n,b);
		return 0;
	}
	if(b[n-1]==0) {
		print(n,a);
		return 0;
	}

	for(i=n-1;i>=0;i--)
	{
		if(a[i]>b[i])
		{
			print(n,b);
			print(n,a);
			break;
		}else if(a[i]<b[i]){
			print(n,a);
			print(n,b);
			break;
		}
	}
	return 0;
}
void print(int n,int a[]) 
{
	int i;
	for(i = n-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
