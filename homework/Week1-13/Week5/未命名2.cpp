# include <stdio.h>
int main(){
	unsigned int a;
	short b;
	a=65535;
	b = (int)a;
	printf("%d\n",b);
	
	if((-1/10.0+3/20.0)== 1/5.0-3/20.0)
	//if(|1/10-3/20| == |1/5-3/20|)
	{
		printf("111\n");
	}
	printf("%.100f\n",1/10.0-3/20.0);
	printf("%.100f",1/5.0-3/20.0);
}
