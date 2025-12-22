#include <stdio.h>
#include <math.h>
void f1(int n,int x,int d);
void f2(int n,int x,int d);
void f3(int n,int x,int y,int d);
void f11(int n,int x,int d);
int main(int argc, char** argv) {
	int n,i,j,k,m;
	scanf("%d",&n);
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=pow(2,n+2-i);j++)
		{
			if(j==1)
			{
				f1(n,i,1);
				printf("\n"); 
			}else if(j==2){
				f2(n,i,1);
				printf("\n"); 
			}else if(j<=pow(2,n+2-i)-1){
				f3(n,i,j-2,1);
				printf("\n"); 
			}else if(j==pow(2,n+2-i)){
				f2(n,i,1);
				printf("\n"); 
			}
		} 
		
		
	 } 
	 f2(n,n+1,1);
		printf("\n");
	f11(n,n+1,1);

	printf("Hello world!\n");
	return 0;
}

void f1(int n,int x,int d)//第2的次方+1行 ,第x重，d是1 
{
	int i;
	if(x == 1)
	{
		printf("+");
		for(i = 0;i<pow(2,n+3-d)-2;i++)
		{
			printf("-");
		} 
		printf("+");
	}else{
		printf("|");
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		} 
		f1(n,x-1,d+1);
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		} 
		printf("|");
	}
}
void f11(int n,int x,int d)//第2的次方+1行 ,第x重，d是1 
{
	int i;
	if(x == 1)
	{
		printf("+");
		for(i = 0;i<pow(2,n+3-d)-2;i++)
		{
			printf("-");
		} 
		printf("+");
	}else{
		printf("+");
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf("-");
		} 
		f11(n,x-1,d+1);
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf("-");
		} 
		printf("+");
	}
}
void f2(int n,int x,int d)//第2的次方+2行 ,第x重，d是1 
{
	int i;
	if(x == 1)
	{
		printf("|");
		for(i = 0;i<pow(2,n+3-d)-2;i++)
		{
			printf(" ");
		} 
		printf("|");
	}else{
		printf("|");
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		} 
		if(x!=1)
		{
			f2(n,x-1,d+1);
		}
		
			for(i = 0;i<pow(2,n+1-d)-1;i++)
			{
				printf(" ");
			} 
		printf("|");	
	}
 } 
 void f3(int n,int x,int y,int d)//第2的次方+3...行 ,第x重，d是1 
{
	int i;
	if(x == 1)
	{
		printf("|");
		for(i = 0;i<pow(2,n+2-d)-2-y;i++)
		{
			printf(" ");
		}
		printf("/");
		for(i = 0;i<2*y;i++)
		{
			printf(" "); 
		}
		printf("\\");
		for(i = 0;i<pow(2,n+2-d)-2-y;i++)
		{
			printf(" ");
		}
		printf("|");
		
	}else{
		printf("|");
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		} 
		if(x!=1)
		{
			f3(n,x-1,y,d+1);
		}
		
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		}
		printf("|");
	}
	
 } 
 
