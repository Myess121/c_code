#include <stdio.h>

int main(int argc, char** argv) {
	int a,b;
	int cnt,i,x;
	scanf("%d/%d",&a,&b);
	printf("0.");
	for(cnt=1;;cnt++)
	{
		a *= 10;
		i = a / b;
		a = a % b;
		if(a == 0)
		{
			printf("%d\n",i);
			break;
		}
		printf("%d",i);
		if(cnt == 200)
		{
			printf("\n");
			break;
		}
	}

	return 0;
}
