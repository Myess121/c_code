#include <stdio.h>
#include <math.h>
void f1(int n,int x,int d,char m,char z,char p,char q);
void f3(int n,int x,int y,int d);

int main(int argc, char** argv) {
	int n,i,j,k,m;
	scanf("%d",&n);
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=pow(2,n+2-i);j++)
		{
			if(j==1)
			{
				f1(n,i,1,'+','-','|',' ');
				printf("\n"); 
			}else if(j==2){
				f1(n,i,1,'|',' ','|',' ');
				printf("\n"); 
			}else if(j<=pow(2,n+2-i)-1){
				f3(n,i,j-2,1);
				printf("\n"); 
			}else if(j==pow(2,n+2-i)){
				f1(n,i,1,'|',' ','|',' ');
				printf("\n"); 
			}
		} 
	 } 
	f1(n,n+1,1,'|',' ','|',' ');
	printf("\n");
	f1(n,n+1,1,'+','-','+','-');
	printf("\n");
	return 0;
}
//f1:"+,-,|, "   f2: '|',' ','|',' '   f11:'+','-','+','-'
void f1(int n,int x,int d,char m,char z,char p,char q)//没有撇捺的 ，n就是n，第x重，d写1，用来计数，剩下的四个是符号 
{
	int i;
	if(x == 1){
		printf("%c",m);
		for(i = 0;i<pow(2,n+3-d)-2;i++)
		{
			printf("%c",z);
		} 
		printf("%c",m);
	}else{
		printf("%c",p);
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf("%c",q);
		} 
		f1(n,x-1,d+1,m,z,p,q);
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf("%c",q);
		} 
		printf("%c",p);
	}
}

 void f3(int n,int x,int y,int d)//第2的次方+3...行 ,第x重，d是1 
{
	int i;
	if(x == 1){
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
		if(x!=1){
			f3(n,x-1,y,d+1);
		}
		for(i = 0;i<pow(2,n+1-d)-1;i++)
		{
			printf(" ");
		}
		printf("|");
	}
 } 
