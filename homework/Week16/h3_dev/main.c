#include <stdio.h>

int main(int argc, char** argv) {
	char a[50],x;
	int n,i;
	scanf("%s",a);
	scanf("%d",&n);
	FILE *fp = fopen (a,"r");
	if(fp == NULL){
		printf("File Name Error.\n");
		return 0;
	}
	while(n>1 && (x = fgetc(fp))!= EOF)
	{
		if(x == '\n'){
			n --;
		}
	}
	if(x == EOF)
	{
		printf("Line No Error.\n");
	}
	while((x = fgetc(fp))!= EOF){
		printf("%c",x);
		if(x == '\n'){
			return 0;
		}else if(x == EOF){
			printf("\n");
			return 0;
		}
	}
	
	return 0;
}
