#include <stdio.h>
long long gong(long long x,long long y);
long long jue(long long x);
int main(int argc, char** argv) {
	long long a,b,n;
	long long u=0,v=1,f,e,i,h ;
	scanf("%lld %lld %lld",&a,&b,&n);
	f = a;
	e = b;
	if(n>=b)
	{
		u = a / gong(a,b);
		v = b / gong(a,b);
	}else{		
		for (i=1;i<=n;i++)//分母遍历 
		{
			for(h = a * i / b;h<=a * i / b +1;h++)//分子可能是a*i/b或他加一 
			{
				if(e*jue(h*b-i*a)<f*i*b){//之前的差的绝对值是f/e，这里如果更接近 
					f=jue(h*b-i*a);//更新差的绝对值f/e
					e=i*b;
					u = h;//更新分数 
					v = i;
				}else if(e*jue(h*b-i*a) == f*i*b){//绝对值差相等 
					if(i<v){//比分母 
						u = h;
						v = i;
					}else if(i==v){
						if(h<u){//比分子 
							u = h;
							v = i;	
						}
					}
				}
			}
			
		}
	}
	printf("%lld/%lld\n",u,v);
	return 0;
}
long long gong(long long x,long long y)
{
	long long z;
	while(1)
	{
		z = x % y ;
		if(z == 0){
			break;
		}
		x = y;
		y = z;		
	}//y是公约数 
	return y;
}
long long jue(long long x)
{
	if(x<0){
		x=-x;
	}
	return x;
}


