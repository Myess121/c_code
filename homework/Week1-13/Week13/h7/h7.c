#include <stdio.h>  
#include <string.h>
int qushu(char* p,int *pa,int *pb);
int fangshu(char *p,int i,int num);
int jia(char * p);
int jian(char * p);
int cheng(char * p);
int chu(char * p);

int main ()
{
    int i = 1;
    char a[150];
    memset (a,0,sizeof(a));
    a[0] = ' ';
    while ((a[i] = getchar()) != '\n')
    {
        i ++;
    }
    a[i] = ' ';
    for(i = 0;a[i] != 0;i++)
    {
        if(a[i] == '+'){
            a[i] = ' ';
            jia(&a[i]);
        }else if(a[i] == '-'&&a[i+1] == ' '){
            a[i] = ' ';
            jian(&a[i]);
        }else if(a[i] == '*'){
            a[i] = ' ';
            cheng(&a[i]);
        }else if(a[i] == '/'){
            a[i] = ' ';
            chu(&a[i]);
        }
    }
    for(i = 0;a[i] == ' ';i++){}
    for(;a[i]!= ' ';i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}
int qushu(char* p,int *pa,int *pb)
{
    int  b[100];
    int i,j,k;
    *pa = 0;
    *pb = 0;
    for(i = 0;p[i] == ' ';i--){}
    j = 1;
    for(;p[i] != ' ' && p[i] != '-';i--)
    {
        *pa = *pa + (int)(p[i]-'0') * j;
        p[i] = ' ';
        j *= 10;
    }
    if(p[i] == '-')
    {
        *pa *= -1;
        p[i] = ' ';
    }
    for(;p[i] == ' ';i--){}
    j = 1;
    for(;p[i] != ' ' && p[i] != '-';i--)
    {
        *pb = *pb + (int)(p[i]-'0') * j;
        p[i] = ' ';
        j *= 10;
    }
    if(p[i] == '-')
    {
        *pb *= -1;
        p[i] = ' ';
        return i;
    }
    return i+1;//返回保证前面有空格
}
int fangshu(char *p,int i,int num)
{
    int k = 0,b[100];
    memset(b,0,sizeof(b));
    if(num <0){
        p[i] = '-';
        num *= -1;
        i++;
    }
    do{
        b[k] = num % 10;
        num = num / 10;
        k++;
    }while(num != 0);
    for(k = k - 1;k>=0;k--)
    {      
        p[i] = b[k] + '0';   
        i++;    
    }
    return i;
}
int jia(char * p)
{
    int pa,pb,*p1 = &pa,*p2 = &pb,n;
    n = qushu(p,p1,p2);
    fangshu(p,n,*p1+*p2);
}
int jian(char * p)
{
    int pa,pb,*p1 = &pa,*p2 = &pb,n;
    n = qushu(p,p1,p2);
    fangshu(p,n,*p2-*p1);
}
int cheng(char * p)
{
    int pa,pb,*p1 = &pa,*p2 = &pb,n;
    n = qushu(p,p1,p2);
    fangshu(p,n,*p1*(*p2));
}
int chu(char * p)
{
    int pa,pb,*p1 = &pa,*p2 = &pb,n;
    n = qushu(p,p1,p2);
    fangshu(p,n,*p2/(*p1));
}

    