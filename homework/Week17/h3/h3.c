#include <stdio.h>
#include <stdlib.h>
int cmp(const void * a,const void * b);
int main ()
{
    char a[60],x,s[65]= "9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA";
    int i,arr[60],j,n = 0;
    gets(a);
    for(i = 0;a[i] != 0;i++)
    {
        for(j = 0;s[j] != a[i];j++);
        arr[i] = j;
    }
    n = i;
    qsort(arr,n,sizeof(int),cmp);
    for(i = 0;i<n;i++)
    {
        printf("%c",s[arr[i]]);
    }
    printf("\n");
    


    return 0;
}
int cmp(const void * a,const void * b)
{
    
    return *(int*)a - *(int*)b;
}