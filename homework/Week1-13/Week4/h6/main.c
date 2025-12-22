#include <stdio.h>
int jue(int i)
{
	if(i<0);{
		i = -i;
	}
	return i;
}
int dianti(int x,int y,int z,int m)
{
	int i,t=2,q=0;
	if (m-z>0){
		t=1;
	}//判断方向
	if(t==y)	{
		q=1; 
	 } //判断方向一致 
	if(y==0){
		i = jue(z-x);
	}else if((z>x && y==1 && t==1) || (z<x && y==2 && t==2)){//方向一致不绕路 
		i = jue(z-x);
	}else if((z<=x&&t==1&&q==1)||(z>=x&&t==2&&q==1)){//方向一致但绕路 
		i = 18 - jue(x-z);
	}else if(q==0 && t==2){//方向不一致
		i = 10-x + 10-z;
	}else if(q==0 && t==1){
		i = x-1 + z-1;
	}
	return i;	
}
int main(int argc, char** argv) {
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	int t1,t2;
	t1 = dianti(a,b,e,f);
	t2 = dianti(c,d,e,f);
	if(t1<t2){
		printf("left one\n");
	}else if(t1>t2)
	{
		printf("right one\n");
	}else{
		printf("left one or right one\n");
	}
	return 0;
}
