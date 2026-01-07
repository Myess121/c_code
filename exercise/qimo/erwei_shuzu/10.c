#include <stdio.h>
#include <string.h>
int main()
{
    int a[22][22],i,j,m,n,k,x,y,cnt;
    char c;
    memset (a,0,sizeof(a));
    scanf("%d %d",&m,&n);
    getchar ();
    for(i = 1;i<=m;i++)
    {
        for(j = 1;j<=n;j++)
        {
            c = getchar();
            if(c == '#'){
                a[i][j] = 2;
            }
        }
        getchar ();
    }
    scanf("%d",&k);
    while(k>0){
        cnt = 0;
        scanf("%d %d",&x,&y);
        x++;
        y++;
        if(a[x][y]){
            cnt ++;
            a[x][y] = 0;
        }
        if(a[x][y+1]){
            a[x][y+1]--;
            if(a[x][y+1] == 0){
                cnt ++;
            }
        }
        if(a[x][y-1]){
            a[x][y-1]--;
            if(a[x][y-1] == 0){
                cnt ++;
            }
        }
        if(a[x+1][y]){
            a[x+1][y]--;
            if(a[x+1][y] == 0){
                cnt ++;
            }
        }
        if(a[x-1][y]){
            a[x-1][y]--;
            if(a[x-1][y] == 0){
                cnt ++;
            }
        }
        printf("%d\n",cnt);
        k--;
    }

}