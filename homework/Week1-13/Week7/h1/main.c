#include <stdio.h>

int main(int argc, char** argv) {
	int m,n,cnt=0,s,i,j;
	printf("KFC  McDonald  PissaHut\n");
	while (scanf("%d %d",&m,&n)!= EOF)
	{
		cnt = 0;
		for(i = m;i>=0;i--)
		{
			for(j = m - i;j>=0;j--)
			{ 
				if(12*i + 4*j + 8*m == n)
				{
					printf("%d %d %d\n",i,j,m-i-j);
					cnt ++;
				}
			}
		}
		if(cnt == 0)
		{
			printf("No Solution!\n");
		}
	}
	return 0;
	}
	
	
	/*
int main(int argc, char** argv) {
	int a[64] = {0};
	int b[64] = {0};
	int t=-1;
	int m,n,cnt=0,s,i,j;
	while (scanf("%d %d",&m,&n)!= EOF)
	{
		t ++;
		a[t] = m;
		b[t] = n;
		
	}
	printf("KFC  McDonald  PissaHut\n");//i,j,k
	for(s=0;s<=t;s++)
	{
		cnt = 0;
		for(i = a[s];i>=0;i--)
		{
			for(j = a[s] - i;j>=0;j--)
			{ 
				if(12*i + 4*j + 8*a[s] == b[s])
				{
					printf("%d %d %d",i,j,a[s]-i-j);
					cnt ++;
				}
			}
		}
		if(cnt == 0)
		{
			printf("No Solution!\n");
		}
	}
	return 0;
}
*/

