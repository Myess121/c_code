#include <stdio.h>
#include <string.h>

int main ()
{
    int n,j,flag1,flag2,flag3,flag4,flag,i;
    char s[21];
    scanf("%d",&n);
    getchar();
    for(i = 0;i<n;i++)
    {
        flag1 = 0;
        flag2 = 0;
        flag3 = 0;
        flag4 = 0;
        flag = 0;
        j = 0;
        memset(s,0,sizeof(s));
        do{
            s[j] = getchar();
            j++;
        }while(s[j-1] != '\n');
        s[j-1] = 0;
        if(s[5] == 0){
            printf("Not Safe\n");
            continue;
        }
        j = 0;
        while(s[j] != 0){
            if(s[j] <= '9' && s[j] >= '0'){
                flag1 = 1;
            }else if(s[j] <= 'z' && s[j] >= 'a'){
                flag2 = 1;
            }else if(s[j] <= 'Z' && s[j] >= 'A'){
                flag3 = 1;
            }else {
                flag4 = 1;
            }
            j++;
        }
        flag = flag1 + flag2 + flag3 + flag4;
        switch(flag){
            case 1 :
            printf("Not Safe\n");
            break;
            case 2 :
            printf("Medium Safe\n");
            break;
            case 3:
            case 4:
            printf("Safe\n");
            break;
        }
    }
    return 0;
}