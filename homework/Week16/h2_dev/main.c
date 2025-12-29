#include <stdio.h>
int main()
{
    char a[50],b[50];
    char x,y;
    int flag;
    scanf("%s %s",a,b);
    FILE * fp = fopen(a,"r");
    FILE *f2 = fopen(b,"r");
    if (!fp || !f2) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    while((x = fgetc(f2))!=EOF)
    {
        rewind(fp);
        flag = 0;
        while((y = fgetc(fp))!=EOF)
        {
            if(y == x){
                y = fgetc(fp);
                if(y == ','){
                    y = fgetc(fp);
                    printf("%c",y);
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0){
        	printf("%c",x);
		}
    }

    return 0;
}
