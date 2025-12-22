#include <stdio.h>

int main(int argc, char** argv) {
	int n,i,j;
	char x,t;
	scanf("%d %c",&n,&x);
	if(x<='z'&&x>='a'){
		x= x-32;
	}else if(x>'z'||x<'A'||(x>'Z'&&x<'a')){
		printf("Input error!\n");
		return 0;
	}
	t = x; 
	for(i = 0;i<n;i++)
	{
		if(i == 0){
			printf("%c",t);
		} else{
			printf(" %c",t);
		}
		t++;
		if(t>'Z'){
			t = 'A';
		}
	}
	printf("\n");
	for(i = 1;i<n-1;i++)
	{
		x++;
		if(x>'Z'){
			x = 'A';
		}
		printf("%c",x);
		for(j=0;j<n-2;j++)
		{
			printf("  ");
		}
		printf(" %c",t);
		t++;
		if(t>'Z'){
			t = 'A';
		}
		printf("\n");
	}
	if(n == 1){
		return 0;
	}
	for(i = 0;i<n;i++)
	{
		x++;
		if(x>'Z'){
			x = 'A';
		}
		if(i == 0){
			printf("%c",x);
		} else{
			printf(" %c",x);
		}
	}
	printf("\n");
	return 0;
}
