#include <stdio.h>

int main(int argc, char** argv) {
	char s[100],x;
	int a = 0,b = 0,flag1 = 0,flag2 = 0;
	scanf("%s",s);
	FILE* fp = fopen(s,"r"); 
	while((x = fgetc(fp)) != ' ')
	{
		if(x == '-'){
			flag1 = 1;
			continue;
		}
		a = 10*a + x - '0';
	}
	if(flag1 == 1){
		a *= -1;
	}
	do
	{
		x = fgetc(fp);
		if((x>'9' || x<'0')&&x!='-'){
			break;
		}
		if(x == '-'){
			flag2 = 1;
			continue;
		}
		b = 10*b + x - '0';
	}while(1);
	if(flag2 == 1){
		b *= -1;
	}
	printf("%d\n",a+b);
	return 0;
}
