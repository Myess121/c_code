#include <stdio.h>
#include <string.h>
int dfs(int p[12][12],int pe[12][12],int q[12][12],int x,int y,int p2[12][12],int pe2[12][12],int flo);
int ddfs(int m,int n,int p[12][12],int pe[12][12],int q[12][12],int p2[12][12],int pe2[12][12],int flo);
void biaoji(int m,int n,int f[12][12],int flo);
int main()
{
    int i,a1[12][12],b1[12][12],j,a2[12][12],b2[12][12],c[12][12],xx,yy,xx1,yy1,floor = 2,t,z;
    memset(a1,0,sizeof(a1));
    memset(b1,0,sizeof(b1));
    memset(a2,0,sizeof(a2));
    memset(b2,0,sizeof(b2));
    memset(c,0,sizeof(c));
    for(i=1;i<11;i++)
    {
        for(j = 1;j<11;j++)
        {
            scanf("%d",&a1[i][j]);    
            if(a1[i][j] == 223){
                xx = i;
                yy = j;
            } 
        }
        
    }
    for(i=1;i<11;i++)
    {
        for(j = 1;j<11;j++)
        {
            scanf("%d",&b1[i][j]);   
            if(b1[i][j] == 7){
                xx1 = i;
                yy1 = j;
            }   
        }
        
    }  
    t = dfs(a1,a2,c,xx,yy,b1,b2,floor);
    if(t == 0)
    {
        printf("世上本没有路......\n");
        return 0;
    }
    c[xx1][yy1] = 7;
    for(i=1;i<11;i++)
    {
        z = 0;
        for(j = 1;j<11;j++)
        {
            if(c[i][j] == 12)
            {
                printf("  ");                   
                printf("%d",c[i][j]); 
            }else if(i == xx && j == yy){
                printf("  ");                   
                printf("xx"); 
            }else if(c[i][j] == 3){
                printf("   ");                   
                printf("+");
            }else{
                printf("   ");                   
                printf("%d",c[i][j]);
            }  
        }
        printf("\n");
    }  
    return 0;
}
int dfs(int p[12][12],int pe[12][12],int q[12][12],int x,int y,int p2[12][12],int pe2[12][12],int flo)
{
    int flag = 0;
    pe[x][y] = 1;
    flag = ddfs(x,y-1,p,pe,q,p2,pe2,flo);
    if(flag == 1){
            return 1;
    }
    flag = ddfs(x,y+1,p,pe,q,p2,pe2,flo);
    if(flag == 1){
            return 1;
    }
    flag = ddfs(x+1,y,p,pe,q,p2,pe2,flo);
    if(flag == 1){
            return 1;
    }
    flag = ddfs(x-1,y,p,pe,q,p2,pe2,flo);
    if(flag == 1){
            return 1;
    }
    return 0;
    
    
}
int ddfs(int m,int n,int p[12][12],int pe[12][12],int q[12][12],int p2[12][12],int pe2[12][12],int flo)
{
    int flag = 0,flo2;
    if(p[m][n] == 1&&pe[m][n] == 0){
        flag = dfs(p,pe,q,m,n,p2,pe2,flo);
        if(flag == 1){
            biaoji(m,n,q,flo);
            return 1;
        }
    }else if(p[m][n] == 2){
        p2[m][n] = 3;
        if(pe2[m][n] == 0){
            if(flo == 1){
                flo2 = 2;
            }else{
                flo2 = 1;
            }
            flag = dfs(p2,pe2,q,m,n,p,pe,flo2);
            if(flag == 1){
                biaoji(m,n,q,-1);
                return 1;
            }
        }     
        if(pe[m][n] == 0){
            flag = dfs(p,pe,q,m,n,p2,pe2,flo);
            if(flag == 1){
                biaoji(m,n,q,flo);
                return 1;
            }
        }
        
       
    }else if(p[m][n] == 7){
        biaoji(m,n,q,1);
        return 1;
    }
    return 0;
}

void biaoji(int m,int n,int f[12][12],int flo)
{
    if(flo == -1){
        f[m][n] = 3;
    }else if(f[m][n] == 0){
        f[m][n] = flo;
    }else{
        f[m][n] = 12;
    }
    
}