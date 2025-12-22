#include<stdio.h>
int way[10][10],map1[10][10],map2[10][10],find,ox,oy;
void dfs1(int x,int y){
    if(find) return;
    if(map1[x][y]==0) return;
    if(map1[x][y]==7){
        find=1;
        return;
    }
    if(map1[x][y]==2&&way[x][y]!='x'){
        way[x][y]='x';
        dfs2(x,y);
    }
    else if(way[x][y]==2) way[x][y]=12;
    else way[x][y]=1;
    if(way[x+1][y]!=1&&way[x+1][y]!=12&&way[x+1][y]!='x') dfs1(x+1,y);
    if(way[x-1][y]!=1&&way[x-1][y]!=12&&way[x-1][y]!='x') dfs1(x-1,y);
    if(way[x][y+1]!=1&&way[x][y+1]!=12&&way[x][y+1]!='x') dfs1(x,y+1);
    if(way[x][y-1]!=1&&way[x][y-1]!=12&&way[x][y-1]!='x') dfs1(x,y-1);
    if(find) return;
    way[x][y]=0;
}

void dfs2(int x,int y){
    if(find) return;
    if(map2[x][y]==0) return;
    if(map2[x][y]==2&&way[x][y]!='x'){
        way[x][y]='x';
        dfs1(x,y);
    }
    else if(way[x][y]==1) way[x][y]=12;
    else way[x][y]=2;
    if(way[x+1][y]!=2&&way[x+1][y]!=12&&way[x+1][y]!='x') dfs2(x+1,y);
    if(way[x-1][y]!=2&&way[x-1][y]!=12&&way[x-1][y]!='x') dfs2(x-1,y);
    if(way[x][y+1]!=2&&way[x][y+1]!=12&&way[x][y+1]!='x') dfs2(x,y+1);
    if(way[x][y-1]!=2&&way[x][y-1]!=12&&way[x][y-1]!='x') dfs2(x,y-1);
    if(find) return;
    way[x][y]=0;
}

int main(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",map2[i][j]);
            if(map2[i][j]==223){
                ox=i;
                oy=j;
            }   
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",map1[i][j]);
        }
    }
    dfs2(ox,oy);
    if(find) for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map1[i][j]==223) printf("%4s","ss");
            else if(way[i][j]=='x') printf("%4c",'x');
            else printf("%4d",way[i][j]);
        }
    }
    else printf("世上本没有路......\n");
    return 0;
}