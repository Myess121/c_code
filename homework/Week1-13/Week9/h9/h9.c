#include <stdio.h>

int main()
{
    int n,m,a[1000],i,j,flag = 0,k;
    scanf("%d %d",&n,&m);
    for(i = 0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0;i<n;i++)
    {
        k = 0;
        for(j = 0;j<m;j++)
        {
            if (a[j] == i){
                k = 1;
                break;
            }
        }
        if(k == 0){
            printf("%d ",i);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Go!\n");
        return 0;
    }
    printf("\n");
    return 0;
}