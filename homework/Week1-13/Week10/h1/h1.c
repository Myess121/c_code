#include <stdio.h>
#include <string.h>

int main(){
    char a[1000],b[1000],c[2000];
    int i,j=0,k=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    do{
        a[j] = getchar();
        j++;
    }while(a[j-1] != '\n');
    a[j-1] = 0;
    j = 0;
    do{
        b[j] = getchar();
        j++;
    }while(b[j-1] != '\n');
    b[j-1] = 0;
  //  scanf("%s",a);
    //scanf("%s",b);
    j = 0;
    for(i=0;i<2000;i++)
    {
        if(a[j] == 0 && b[k]!=0){
            printf("%s\n",b+k);
            return 0;
        }else if(a[j]!=0 && b[k]== 0 ){
            printf("%s\n",a+j);
            return 0;
        }else if(a[j] >= b[k]){
            printf("%c",b[k]);
            k++;
        }else if(a[j]<b[k]){
            printf("%c",a[j]);
            j++;
        }
    }
    printf("\n");
    return 0;
}