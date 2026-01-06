#include <stdio.h>

int main()
{
    int n,k,s[50],i,m = -1,j;
    scanf("%d %d",&n,&k);
    for(i = 0;i<n;i++)
    {
        s[i] = i+1;
    }
    for(int i = 0;i < n-1;i++)
    {
        for(j = 0;j<k;j++)
        {  
            m++;
            if(m>=n){
                m = 0;
            }   
            while(s[m] == 0)
            {
                m++;
                if(m>=n){
                m = 0;
                }
            }    
        }
        s[m] = 0;
        printf("No%d: %d\n",i+1,m+1);
    }
    for(i = 0;s[i] == 0;i++) {}
    printf("Last No is: %d\n",i+1); //答案初始下标为1
    return 0;
}