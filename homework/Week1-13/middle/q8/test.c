#include <stdio.h>

int main(int argc, char** argv) {
	int n;
	int i,j,flag,flag2 = 0,cnt;
	scanf("%d",&n);
	printf("%d=",n);
	for(i = 2;;i++)
	{
		flag = 0;
		for (j = 2;j<i;j++)
		{
			if(i%j == 0){
				flag = 1;
				break;
			}
		}
		if(i == 2){
			flag = 0;
		}
		if(flag == 0){
            cnt = 0;
			while(n % i == 0)
			{
				n = n / i ;
                cnt ++;
			}
			if(cnt == 0){
				continue;;
			}
			if(flag2 == 1){
				printf("*");
			}else{
				flag2 = 1;
			}
			if(cnt ==1){
				printf("%d",i);
			}else if(cnt > 1){
				printf("%d^%d",i,cnt);
			}
			if(n==1){
				printf("\n");
				return 0;
			}
		}
	}

	return 0;
}
