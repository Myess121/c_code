#include <stdio.h>
#include <string.h>
void pai(int x);
int n,a[9],b[10];
void print();
int main()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&n);
    pai(0);
    return 0;
}
void pai(int x)
{
    int i;
    if(x == n)
    {
        print();
    }
    for(i = 1;i<=n ;i++)
    {
        if(b[i] == 0){
            a[x] = i;
            b[i] = 1;
            pai(x+1);
            b[i] = 0; 
        }
    }
}
void print()
{
    int i;
    for(i = 0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}