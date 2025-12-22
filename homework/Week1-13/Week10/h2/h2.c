#include <stdio.h>
#include <string.h>

int main ()
{
    int i,flag = 0;
    char s[6];
    memset(s,0,sizeof(s));
    scanf("%s",s);
    if(s[4]>'9'||s[4]<'0'){
        printf("no.\n");
        return 0;
    }
    for(i = 0;i<4;i++)
    {
        if(s[i]>'Z'||(s[i]<'A'&&s[i]>'9')||s[i]<'0'||s[i]=='I'||s[i]=='O'){
            printf("no.\n");
            return 0;
        }else if(s[i]>='A'&&s[i]<='Z')
        {
            flag ++;
        }
    }
    if(flag<2){
        printf("no.\n");
    }else{
        printf("ok.\n");
    }
    return 0;
}