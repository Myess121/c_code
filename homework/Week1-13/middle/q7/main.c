#include <stdio.h>

int main(int argc, char** argv) {
	char t1, t,x;
	int n ,i,j;
	scanf("%d %c",&n,&x);
	t = x + (char)n-1;
	
	while(t>'Z')
	{
		t -= 26;
	}
	t1 = t;
	for(i=0; i<n-1;i++)
	{
		printf(" ");
	}
	for(i=0; i<n; i++)
	{
		printf("%c",t);
		t++;
		if(t>'Z'){
			t -= 26;
		}
	}
	printf("\n"); 
	if(n == 1){
		return 0;
	} 
	for(i = 0;i<n-2;i++)
	{
		t1--;
		if(t1<'A')
		{
			t1 += 26;
		}
		for(j = 0;j<n-2-i;j++)
		{
			printf(" ");
		}
		printf("%c",t1);
		for(j = 0;j<n +2*i ;j++)
		{
			printf(" ");
		}
		printf("%c\n",t);
		t++;
		if(t>'Z'){
			t -= 26;
		}
	}
	t1--;
	if(t1<'A')
		{
			t1 += 26;
		}
	for(i=0;i<3*n -2;i++)
	{
		printf("%c",t1);
		t1++;
		if(t1>'Z'){
			t1 -= 26;
		}
	}
	printf("\n"); 
	return 0;
}
