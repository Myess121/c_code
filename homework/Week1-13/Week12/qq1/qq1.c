#include <stdio.h>
#include <string.h>
int pai(int *a,int *b,int n,int x);
int main()
{
    int n,a[9] = {1,2,3,4,5,6,7,8,9},b[9];
    memset (b,0,sizeof(b));
    scanf("%d",&n);
    pai(a,b,n,1);
    return 0;
}

int pai(int *a,int *b,int n,int x)
{
    int i,flag = 0,j;
    if(n != 0){
        for(i = 0;i<n;i++)
            {
                if(b[i] == 0){
                    b[i] = x;
                    pai(a,b,n,x+1);
                    b[i] = 0;
                    flag = 1;
                }
                
            }

    }
    if(flag == 0){
        for(i = 1;i<=n;i++)
        {
            for(j = 0;j<n;j++)
            {
                if(b[j] == i)
                {
                    printf("%d",a[j]);
                    break;
                }
            }
        }
        printf("\n");
    }
    
}