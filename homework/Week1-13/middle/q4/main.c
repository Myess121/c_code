#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	int s[23] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83};
	int cnt,sum = 0,flag = 0,i,j,y;
	double x;
	int arr[1000000];
	memset(arr, 0, sizeof(arr));
	for(i = 0;;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i] == 0)
		{
			break;
		}
	}
	cnt = i;
	for(i = i-1;i>=0;i--)
	{
		if(arr[i] > 80 || flag == 1){
			flag = 1;
			continue;
		}
		for(j = 0; j<23 ; j ++)
		{
			if(s[j]>arr[i]){
				break;
			}
			sum = sum + s[j];
		}
	 
	}
	if(cnt == 0)
	{
		printf("0\n");
		return 0; 
	}
	if(flag == 1){
		printf("×÷ËÀ°¡!!!!!!\n");
		return 0;
	}
	x = (double)sum / cnt * 10;
//	y = sum / cnt * 10;
	printf("%.0lf\n",x);
 //	printf("%d\n",y);
	return 0;
}
