#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 24

int print(int num);
int s[N] ;  
int n,a,cnt = 0; 
//int zhuan();
//char ar[9] = "11100100";
//int judge();

int main()
{
    int i;
    n = N;
    a = pow(2,N);
//    zhuan();
//    judge();
    for(i = 0;i<a;i++)
    {
        print(i);
    }
    printf("n 等于 %d 时有 %4d 种\n",n,cnt);
    return 0;
}

int print(int num)
{
    int m = 1,i,b = 0;
    memset(s,0,sizeof(s));
    for(i = 0;i<N;i++)
    {
        if(m & num)
        {
//            printf("1");
            if(b == 0)
            {
                s[b] = 1;
                b++;
            }else if(s[b-1] == 1){
                s[b-1] = 0;
                b--;
            }else {
                s[b] = 1;
                b++;
            }
        }else{
//            printf("0");
            if(b == 0)
            {
                s[b] = 2;
                b++;
            }else if(s[b-1] == 2){
                s[b-1] = 0;
                b--;
            }else {
                s[b] = 2;
                b++;
            }
        }
        
        m <<= 1;
    }
    if(b == 0)
    {
//        printf("YES\n");
        cnt ++;
    }else{
//        printf("NO\n");
    }
//    judge();
//    printf("\n");
}
/*
int judge()
{
    int i,m = N,j,k;
    for(k = N/2;k>0;k++)
    {
        for(i = 0;i + 1<m;i++)
        {
            if(s[i] == s[i+1] &&(s[i] == 1||s[i] == 0)){
                for(j = i;j + 2<m;j++)
                {
                    s[j] = s[j+2];
                }
                m -= 2;
                break;
            }
        }
    }
    if(m == 0)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}
*/
/*int zhuan()
{
    int i;
    for(i = 0;i<8;i++)
    {
        if(ar[i] == '0')
        {
            s[i] = 0;
        }else{
            s[i] = 1;
        }
    }

}*/