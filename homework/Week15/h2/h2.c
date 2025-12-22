#include <stdio.h>  
  
typedef struct buy  
{  char  gname;  
   int   sname;  
   int   gprice;  
} BUY;  
  
int main( )  
{  int i, j, n;  
   int min, price[10][3];  
   int findm( int n, int price[][3], BUY scheme[] );  
  
   static BUY scheme[3]={ {'A', 0, 0}, {'B', 0, 0}, {'C', 0, 0} };  
  
   scanf( "%d", &n );  
   for( i = 0; i < n; i++ )  
    for( j = 0; j < 3; j++ )  
       scanf( "%d", &price[i][j] );  
  
   min = findm( n, price, scheme );  
  
   printf("Total Money are : %d\nGoods-Name  Shop-Name  Goods-Price\n", min );  
   for ( i=0; i < 3; i++ )  
       printf("         %c:%10d%13d\n", scheme[i].gname, scheme[i].sname, scheme[i].gprice );  
   return 0;  
}  
  
 int findm( int n, int gp[ ][3], BUY schm[ ] )  
 {              
    int i,j,x,y,z,k,min;
    min = gp[0][0] + gp[1][1] + gp[2][2];
    x = 0;
    y = 1;
    z = 2;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n;j++)
        {
            if(j == i)
            {
                continue;
            }
            for(k = 0;k<n;k++)
            {
                if(k == i || k == j)
                {
                    continue;
                }
                if(gp[i][0] + gp[j][1] + gp[k][2] < min){
                    x = i;
                    y = j;
                    z = k;
                    min = gp[i][0] + gp[j][1] + gp[k][2];
                }

            }
        }
    }
    schm[0].sname = x + 1;
    schm[0].gprice = gp[x][0];
    schm[1].sname = y + 1;
    schm[1].gprice = gp[y][1];
    schm[2].sname = z + 1;
    schm[2].gprice = gp[z][2];
    return min;

 }                