#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N=100+5,M=N*2;
const double Eps=1e-9;
int T=0,n,m,tot_Y,tot_s;
double Y[M];
struct Segment{
    double x,L,R;
    int v;
    void set(double x_,double L_,double R_,int v_){
        x=x_,L=L_,R=R_,v=v_;
    }
}s[M];
struct SegTree{
    int cnt;
    double sum;
}t[M*4];
bool cmp_s(Segment a,Segment b){
    return a.x<b.x;
}
void build(int rt,int le,int ri){
    t[rt].cnt=0;
    t[rt].sum=0;
    if (le==ri)
        return;
    int mid=(le+ri)>>1,ls=rt<<1,rs=ls|1;
    build(ls,le,mid);
    build(rs,mid+1,ri);
}
void pushup(int rt,int le,int ri){
    int ls=rt<<1,rs=ls|1;
    if (t[rt].cnt)
        t[rt].sum=Y[ri+1]-Y[le];
    else if (le==ri)
        t[rt].sum=0;
    else
        t[rt].sum=t[ls].sum+t[rs].sum;
}
void update(int rt,int le,int ri,int xle,int xri,int d){
    if (le>xri||ri<xle)
        return;
    if (xle<=le&&ri<=xri){
        t[rt].cnt+=d;
        pushup(rt,le,ri);
        return;
    }
    int mid=(le+ri)>>1,ls=rt<<1,rs=ls|1;
    update(ls,le,mid,xle,xri,d);
    update(rs,mid+1,ri,xle,xri,d);
    pushup(rt,le,ri);
}
int find_double(double x){
    int le=1,ri=m,mid;
    while (le<=ri){
        mid=(le+ri)>>1;
        if (abs(x-Y[mid])<Eps)
            return mid;
        if (Y[mid]<x)
            le=mid+1;
        else
            ri=mid-1;
    }
}
int main(){
    while (scanf("%d",&n)&&n){
        tot_Y=tot_s=0;
        for (int i=1;i<=n;i++){
            double xA,yA,xB,yB;
            scanf("%lf%lf%lf%lf",&xA,&yA,&xB,&yB);
            if (yB-yA<Eps||xB-xA<Eps)
                continue;
            Y[++tot_Y]=yA,Y[++tot_Y]=yB;
            s[++tot_s].set(xA,yA,yB,1);
            s[++tot_s].set(xB,yA,yB,-1);
        }
        sort(Y+1,Y+tot_Y+1);
        sort(s+1,s+tot_s+1,cmp_s);
        m=1;
        for (int i=2;i<=tot_Y;i++)
            if (Y[i]-Y[i-1]>Eps)
                Y[++m]=Y[i];
        build(1,1,m);
        double ans=0;
        for (int i=1;i<=tot_s;i++){
            ans=ans+(s[i].x-s[i-1].x)*t[1].sum;
            int L=find_double(s[i].L);
            int R=find_double(s[i].R);
            update(1,1,m,L,R-1,s[i].v);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++T,ans);
    }
    return 0;
}