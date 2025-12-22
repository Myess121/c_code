#include <stdio.h>
#include <string.h>
int main()
{
    char a[20][110];
    int i,n,j =0,b[20],c[20],flag ;
    scanf("%d",&n);
    getchar();
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(i = 0;i<n;i++)
    {
        j = 0;
        while( (a[i][j] = getchar()) != '\n')
        {
            if(a[i][j] == ','){
                if(a[i][j-1] == 'g'&&a[i][j-2] == 'n'&&a[i][j-3] == 'o'){
                    b[i] = 1; //标记前半句ong
                }
            }
            j++;
        }
        a[i][j] = '\0';
        if(b[i] == 1 && a[i][j-2] == 'g'&&a[i][j-3] == 'n'&&a[i][j-4] == 'o'){
                    c[i] = j-1; //标记两句ong的句号位置
                }
    }
    for(i = 0;i<n;i++)
    {
        if(c[i] == 0)
        {
            printf("Skipped\n");
        }else{
            flag = 0;
            for(j = c[i];flag != 3;j--)
            {
                if(a[i][j] == ' '){
                    flag ++;
                }
            }
            j = j+2;
            strcpy(a[i]+j,"qiao ben zhong.");
            printf("%s\n",a[i]);
        }
    }
    return 0;
}