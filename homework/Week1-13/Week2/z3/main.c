#include <stdio.h>

int main() 
{
	char ch;
	scanf("%c",&ch);
	
	if(ch<65){
		printf("%c\n",ch);
	} else if(ch>122){
		printf("%c\n",ch);
	} else if(ch>96){
		printf("%c\n",ch-32);
	} else if(ch<91){
		printf("%c\n",ch+32);
	} else {
		printf("%c\n",ch);
	}
	
	return 0;
}
