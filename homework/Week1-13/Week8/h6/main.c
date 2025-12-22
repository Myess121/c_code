#include <stdio.h>

int main(int argc, char** argv) {
	int n,i,j,x = 1,k,t,h;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("%3d",i+1);
	 } 
	 x= 4*n - 4;
	 printf("\n");
	for(i=1;i<(n+1)/2;i++)
	{
		printf("%3d",x);
		t=x;
		h = 4*n - 11;
		for(j = 0;j<i-1;j++)
		{	
			
			t = t+h;
			printf("%3d",t);
			h = h-8;
		}
		for(k = 0;k<n-2*j-2;k++)
		{
			t++;
			printf("%3d",t);
		}
		for(;j>=0;j--)
		{
			h = 4*n-8*j-7;
			t = t-h;
			printf("%3d",t);
			h = h+8;
		}
		printf("\n");
		x--; 
	}
	for(i=(n)/2;i>1;i--)
	{
		printf("%3d",x);
		t=x;
		h = 4*n - 11;
		for(j = i;j>1;j--)
		{	
			t = t+h;
			printf("%3d",t);
			h = h-8;
		}
		for(k = 0;k<n-2*i +1;k++)
		{
			t--;
			printf("%3d",t);
		}
		for(j=i;j>1;j--)
		{
			h = 4*n-8*j+9;
			t = t-h;
			printf("%3d",t);
			h = h+8;
		}
		printf("\n");
		x--; 
	}
	if(x==0){
		return 0;
	} else {
		for (i=0;i<n;i++)
		{
		
		printf("%3d",x);
		x--;
		 } 
		 printf("\n");
		return 0;
	}
}
