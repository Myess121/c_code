#include <stdio.h>
#include <string.h>

int main()
{
    int t[1000000],n,i,cnt = 0,m = 1,dd1 = 0,d1,dd2 = 0;
    memset (t,0,sizeof(t));
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    d1 = 0;
    for(i = 0;i<n-1;i++)
    {
        
        if(t[i] >= t[i+1]){
                cnt ++;
            }else if(cnt > m){
                m = cnt;
                dd1 = d1;
                dd2 = i;
                cnt = 0;
                d1 = i+1;
            }else{
                cnt = 0;
                d1 = i+1;
            }
        }
    
    if(cnt > m){
                dd1 = d1 ;
                dd2 = i;}
    printf("%d %d\n",dd1+1,dd2+1);
    return 0;

}