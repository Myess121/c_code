#include <stdio.h>
#include <string.h>//a是学分，b是成绩
double a[100],b[100];//a是学分，b是成绩
double a_pe = 0.5,b_pe = 88,a_dang = 1,b_dang = 85;
int n = 0;
double *p = a,cnt_a = 0,cnt_b = 0;
int i,k1,k2,k;
void chushihua()
{
        a[0] = 2;   b[0] = 96;
        a[1] = 6;   b[1] = 99;
        a[2] = 1;   b[2] = 93;
        a[3] = 1;   b[3] = 95;
        a[4] = 2;   b[4] = 95;
        a[5] = 2;   b[5] = 92;
        a[6] = 3;   b[6] = 98;
        a[7] = 3;   b[7] = 90;
        a[8] = 0.25;b[8] = 95;
        a[9] = 1;   b[9] = 85;
        a[10] = 2;  b[10] = 97;

}
int dayin(int k1,int k2);

int main ()
{
    memset(a,0,sizeof(a));
    memset (b,0,sizeof(b));
    chushihua();
    while(*p != 0)
    {
        p ++;
        n ++;
    }
    printf("是否所有情况都显示——1为是，0为否\n");
    scanf("%d",&k);
    if(k == 1)
    {
        dayin(0,0);
        dayin(0,1);
        dayin(1,0);
        dayin(1,1);
        return 0;
    }
    
    printf("是否算体育——1为是，0为否\n");
    scanf("%d",&k1);
    printf("是否算中共党史——1为是，0为否\n");
    scanf("%d",&k2);
    dayin(k1,k2);
    return 0;
}

int dayin(int k1,int k2)
{
    cnt_a = 0;
    cnt_b = 0;
    if(k1 == 1)
    {
        a[n] = a_pe;
        b[n] = b_pe;
        n++;
        printf("算上体育，");
    }else{
        printf("不算体育，");
    }
    if(k2 == 1)
    {
        a[n] = a_dang;
        b[n] = b_dang;
        n++;
        printf("算上中共党史，");
    }else{
        printf("不算中共党史，");
    }
    for(i = 0;i<n;i++)
    {
        cnt_b += a[i]*b[i];
        cnt_a += a[i];
    }
    printf("平均分为：%.6lf\n",cnt_b / cnt_a);
    if(k2 == 1)
    {
        n--;
        a[n] = 0;
        b[n] = 0; 
    }
    if(k1 == 1)
    {
        n--;
        a[n] = 0;
        b[n] = 0; 
    }


}
