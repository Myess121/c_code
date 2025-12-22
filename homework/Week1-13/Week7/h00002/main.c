#include <stdio.h>

int main(int argc, char** argv) {
	int a[50] = {0};
	int n,cnt = 1,cntt = 1;
	int pp = 0,qq = 0;
	int i,x,p = 0;
	scanf("%d",&n);
	for(i = 0; i<n ;i++)
	{
		scanf("%d",&a[i]);
		if(i == 0)
		{
			x = a[i];
		}else{
			if(a[i]==x)
			{
				cnt ++;
			}
			
			if(a[i]!=x){
				
				cnt = 1;
				p = i;
				x = a[i];
			}
		}
		if(cntt<cnt)
			{
				pp = p;
				qq = i;
				cntt = cnt;
			}
	}
	if(cntt == 1)
	{
		printf("No equal number list.\n");
	}else{
		printf("The longest equal number list is from %d to %d.\n",pp,qq);
	}

	return 0;
}
