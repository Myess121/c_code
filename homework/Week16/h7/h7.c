#include <stdio.h>
int main ()
{
    int i = 0,n,j,a[500];
    char s[500],x,c = 0,cnt = 1;
    x = getchar();
    c = x;
    while((x = getchar()) != '\n')
    {
        if(x == c)
        {
            cnt ++;
        }else{
            a[i] = cnt;
            s[i] = c;
            c = x;
            cnt = 1;
            i ++;
        }
    }
    a[i] = cnt;
    s[i] = c;
    n = i + 1;
    for(i = 0;i<n;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(a[i] == 1)
            {
                printf("%c",s[i]);
            }else{
                printf("%d%c",a[i],s[i]);
            }
        }else{
            for(j = 0;j<a[i];j++)
            {
                printf("%c",s[i]);
            }
        }
        
    }
    printf("\n");
    return 0;
}