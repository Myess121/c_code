#include <stdio.h>
#include <string.h>

int main()
{
    char a[72],b[66] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="; 
    int j = 0,x,y,z,w,i,flag;
    memset (a,0,sizeof(a));
    do{
        a[j] = getchar();
        j++;
    }while(a[j-1] != '\n');
    a[j-1] = 0;
    flag = (j-1)%3;
    for(i = 0;i<24;i++)
    {
        x = (int)a[3*i]/4;
        y = (int)a[3*i]%4 * 16 + (int)a[3*i+1]/16;
        z = (int)a[3*i+1]%16 * 4 + (int)a[3*i+2]/64;
        w = (int)a[3*i+2] %64;
        if(3*i + 3 > j-1)
        {
            if(flag == 0){
                break;
            }
            if(flag == 1){
                z = 64;
                w = 64;
                printf("%c%c%c%c",b[x],b[y],b[z],b[w]);
                break;
            }
            if(flag == 2){
                w = 64;
                printf("%c%c%c%c",b[x],b[y],b[z],b[w]);
                break;
            }
        }
            printf("%c%c%c%c",b[x],b[y],b[z],b[w]);
    }
    printf("\n");
    return 0;
}