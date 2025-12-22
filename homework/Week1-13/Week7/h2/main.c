#include <stdio.h>

int main(int argc, char** argv) {
	int z;
	scanf("%d",&z);
	z *= 100;
	if(z%160 == 0){
		printf("%d,%d,%d\n",z/16 , 3*z/40 , 9*z/160);
	}else{
		printf("No change.\n");
	}
	return 0;
}
