#include <stdio.h>
#include <string.h>
int shiwu(char s[19]);
int shiba(char s[19]);
int main(){
    int n,i,j;
    char s[20];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        if(s[14] == 0){
            printf("Invalid\n");
        }else if(s[15] == 0){
         shiwu(s);
         }else if(s[18]==0&&s[17]!=0){
            shiba(s);
        }else{
            printf("Invalid\n");
        }
    }
    return 0;
}
int shiwu(char s[19])
{
    int j,x[15] = {7,9,10,5,8,4,6,3,7,9,10,5,8,4,2},flag = 0;
    long long a = 0, h = 1,b;
    char y[12]="10X98765432";
    for(j=14; j>=0; j--)
    {
        a = a + h * (int)(s[j] - '0');
        flag = flag + (int)(s[j] - '0')*x[j];
        h *= 10;
    }
    if(a%1000 >= 996 && a%1000 <= 999){
        b = a%1000000000 + (long long)18*1000000000 + (a/1000000000)*100000000000;
        flag = flag + 10;
        flag = flag % 11;
        printf("%lld%c\n",b,y[flag]);
        return 0;
    }else{
        b = a%1000000000 + (long long)19*1000000000 + (a/1000000000)*100000000000;
        flag = flag % 11;
        printf("%lld%c\n",b,y[flag]);
        return 0;
    }
}
int shiba(char s[19])
{
    int j,x[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2},flag = 0;
    long long a = 0, h = 1,b;
    char y[12]="10X98765432";
    for(j=16; j>=0; j--)
    {
        a = a + h * (int)(s[j] - '0');
        flag = flag + (int)(s[j] - '0')*x[j];
        h *= 10;
    }
    flag = flag % 11;
    if(y[flag] != s[17]){
        printf("Invalid\n");
        return 0;
    }
    if(s[7] == '8'){
        if(a%1000 < 996 || a%1000 > 999)
        {
            printf("Invalid\n");
            return 0;
        }
    }
    printf("Valid\n");
    return 0;
}