#include <stdio.h>

int main ()
{
    int Number = 1253;
	int i = Number,len = 1,t = 1;
	while(i > 9)
	{
		i /= 10;
		len ++;
	}
	for(i = 0;i<len ;i++)
	{
		t *= 10;
	}
	for(i = 0;i<len;i++)
	{
		
		//Serial_SendByte(Number / (t/10) + '0');
        printf("%c\n",Number / (t/10) + '0');
		Number %= t;
		t /= 10;

	}
	
}