#include <stdio.h>

int main(int argc, char** argv) {
	int a,h,t,i,j,cnt=0;
	char x;
	scanf("%c %d %d",&x,&a,&h);
	t = (a+1)/2;
	for(;h>0;h--)
	{
		
		for(i = h-1;i>0;i--)
		{
			printf(" ");
		}
		for(j = 0;j<t;j++)
		{
			if((x>'Z'&&x<'a')||x<'A'){
				x += 26;
			}
			printf("%c",x);
			if(x == 'z'||x == 'Z'){
				cnt ++;
			}
			x--;
		}
		x++;
		if(a%2 == 0){
			printf("%c",x);
			if(x == 'z'||x == 'Z'){
				cnt ++;
			}
		}
		for(j = 0;j<t-1;j++)
		{
			x++;
			if((x>'Z'&&x<'a')||x>'z'){
				x -= 26;
			}
			printf("%c",x);
			if(x == 'z'||x == 'Z'){
				cnt ++;
			}
		}
		t++;
		printf("\n");
	}
	if(x>='a'&&x<='z')
	{
		x = 'z';
	 } else{
	 	x = 'Z';
	 }
	printf("所建金字塔共使用%d个字母砖块%c\n",cnt ,x);
	return 0;
}
