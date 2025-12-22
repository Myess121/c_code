#include <stdio.h>
#include <string.h>

int zhuan(char a[11],int a1[10]);//将字符串转化为数组
int MAX(int a[10]);//找数码的最大值
long long zhenzhi(int x[10],int w,int q);//计算十进制的值

int main()
{
    char a[11],b[11];
    int a1[10],b1[10];
    long long z1,z2;//对应十进制的值
    int i,j,x,y,max1,max2,w1,w2;//w是位数
    memset (a1,0,sizeof(a1));//初始化
    memset (b1,0,sizeof(b1));
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    scanf("%s",a);
    scanf("%s",b);
    if((a[0]=='-'&&b[0]!='-')||(b[0]=='-'&&a[0]!='-'))//判正负，但题目好像是正数，所以这里没啥用
    {
        goto there;
    }
    w1 = zhuan (a,a1);
    w2 = zhuan (b,b1);
    max1 = MAX(a1);
    max2 = MAX(b1);
    for (i = max1 + 1;i<=36;i++)
    {
        if(i == 1){//没有一进制，所以i至少2
            i = 2;
        }
        z1 = zhenzhi(a1,w1,i);
        for(j = max2 + 1;j<=36;j++)
        {
            if(j == 1){
            j = 2;
            }
            z2 = zhenzhi(b1,w2,j);
            if(z1 == z2)
            {
                printf("%s (base %d) = %s (base %d)\n",a,i,b,j);
                return 0;//如果有，就结束
            } 
        }
    }
    there:
    printf("%s is not equal to %s in any base 2..36\n",a,b);
    return 0;
}

int zhuan(char a[11],int a1[10])
{
    int i,j=0;
    for(i = 9;i>=0;i--)
    {
        if(a[i]==0){
            continue;
        }else if(a[i]=='-'){//有符号不用管，因为初始化了，而且这里是倒序排的数码
            continue;
        }else if(a[i] <= '9'){
            a1[j] = a[i] - '0';
            j++;
        }else if(a[i]>='A'&&a[i]<='Z'){
            a1[j] = a[i] - 'A' + 10;
            j++;
        }else if(a[i]>='a'&&a[i]<='z'){//防止有小写
            a1[j] = a[i] - 'a' + 10;
            j++;
        }
    }
    for(i = 9;i>=0;i--)//判位数
    {
        if(a1[i]!=0)
        {
            return i+1;
        }
    }
    return 1;
}
int MAX(int a[10])
{
    int m,i;
    m = a[0];
    for(i=1;i<10;i++)
    {
        if(m<a[i]){
            m = a[i]; 
        }
    }
    return m;
}
long long zhenzhi(int x[10],int w,int q)
{
    int i;
    long long z = 0,a=1;
    for(i=0;i<w;i++)
    {
        z = z + (long long)(x[i])*a;
        a *= q;
    }
    return z;
}