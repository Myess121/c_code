#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0,j;
    char a[200],b[2] ="-",*p = a;
    memset(a,0,sizeof(a));
    while((a[i] = getchar()) != '\n')
    {
        i++;
    }
    a[i] = 0;
    i = 0;
    while(1)
    {
        p = strstr(p,b);
        while(&a[i+1]!=p)
        {
            if(a[i] == 0){
                printf("\n");
                return 0;
            }
            printf("%c",a[i]);
            i++;
        }
        if((a[i]>='A' &&a[i] <= 'Z')&&(a[i+2]>='A' &&a[i+2] <= 'Z')&&a[i]<a[i+2]){
            for(j = 0;a[i] + j <= a[i+2];j++)
            {
                printf("%c",a[i]+j);
            }
            i += 3;
        }else if((a[i]>='a' &&a[i] <= 'z')&&(a[i+2]>='a' &&a[i+2] <= 'z')&&a[i]<a[i+2]){
            for(j = 0;a[i] + j <= a[i+2];j++)
            {
                printf("%c",a[i]+j);
            }
            i += 3;
        }else if((a[i]>='0' &&a[i] <= '9')&&(a[i+2]>='0' &&a[i+2] <= '9')&&a[i]<a[i+2]){
            for(j = 0;a[i] + j <= a[i+2];j++)
            {
                printf("%c",a[i]+j);
            }
            i += 3;
        }else{
            printf("%c%c",a[i],a[i+1]);
            i += 2;
        }
        p = &a[i];

    }
    return 0;
}