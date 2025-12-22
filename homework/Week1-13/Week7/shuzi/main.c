#include <stdio.h>

int main(int argc, char** argv) {
	int num[10]={0,1,2,3,4,5,6,7,8,9};
	int n,a,cnt = 0,c = 0,b,i,k,j;
	scanf("%d %d",&n,&a);
	b = n+ (n-1)/2;
	for(i = a;cnt<b;i ++)
	{
		if(i>9){
			i = 0;	
		}
		if(cnt == 0){
			printf("%d",num[i]);
		}else{
		printf(" %d",num[i]);			
		}
		cnt ++;}
	i -=1;
	b = 2*b;
	if(n%2 == 1){
		b -= 1;
		i -=1;
	}
	for(;cnt<b;i --)
	{
		if(i<0){
			i = 9;
		}
		printf(" %d",num[i]);
		cnt ++;
	}
	printf("\n");//第一行 
	i = a+1;
	for(k = 2;k<n;k++)
	{
		if(i>9){
			i = 0;
		}
		printf(" ");
		for(j=1;j<k-1;j++)
		{
				printf("  ");	
		}
		printf(" %d",num[i]);
		for(j = j+1;j<b-k;j++)
		{
			printf("  ",num[i]);
		}
		printf(" %d",num[i]);
		printf("\n");
		i++;
	}//中间 
	if(n>1)
	{
		printf(" ");
		for(j=1;j<k-1;j++)
		{
			printf("  ");	
		}
		for(cnt=0;cnt<(n+1)/2;cnt++,i++)
		{
			if(i>9){
				i = 0;	
			}
			printf(" %d",num[i]);
		}	
		if(n%2 == 1){
			i -=1;
		}
		for(;cnt<n;cnt++)
		{
			
			if(i<0){
				i = 9;
			}
			i--;
			if(i<0){
				i = 9;
			}
			printf(" %d",num[i]);
		}
		printf("\n"); 
	}
	return 0;
}
