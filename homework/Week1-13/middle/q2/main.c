#include <stdio.h>

int main(int argc, char** argv) {
	int a,b,c,n1,n2,n3;
	int m,n;
	scanf("%d %d",&m,&n);
	for(c = m/n;c>0;c--)
	{
		a = 2 * c;
		b = c + c/2;
		for(n3 = 1;n3<n-1;n3++)
		{
			for (n2 = 1;n2<n-n3;n2++)
			{
				n1 = n - n2 -n3;
				if(a*n1 + b*n2 + c*n3 == m&&n1<n2&&n2<n3){
					printf("Price=%d, A=%d, B=%d, C=%d\n",c,n1,n2,n3);
					return 0;
				}
			}
		}
	}
	return 0;
}
