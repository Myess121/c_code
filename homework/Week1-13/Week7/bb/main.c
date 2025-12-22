#include <stdio.h>
void hanshu(long long t,long long h,int n,int m );

int main(int argc, char** argv) {
	int n;
	scanf("%d",&n);
	hanshu(0,1,n,1);
	return 0;
}
void hanshu(long long t,long long h,int n,int m )
{
	int i;
	int j;
	long long a,x = 0,x1,x2;
	for(i=0;i<=9;i++)
	{
		x = 0; 
		if(h==1&&i == 0)
		{
			continue;
		}
//		printf("第%d轮",i) ;
		a = i*(h) + t;//t是少一位的,h是10的多少次方 
		for(j=1;j<=h;)
		{
//			x = x + (a / j % 10 *10)*(a%(10*h/j));
			x1 =  a / j % 10;
			x2=a%(10*h/j);
			x = x + x1*x2*j;
			j *= 10;
		 } 
		 x =  x%(10*h);
//		x =  a*a%(10*h);
//		printf ("a = %lld    x=%lld\n",a,x);
		if(x == a)
		{
//			printf("x == a");
			if(m==n && a>=h)//m是10的几次方 
			{
				printf("%lld\n",a);
			}else if(m<n){
	//		printf("m<n,\n");
				hanshu(a,10*h,n,m+1);
			}
		}
	}
}

