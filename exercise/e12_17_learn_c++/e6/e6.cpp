#include<bits/stdc++.h>
using namespace std;
int n ,m,p,a[5005],s[5005];
int link(int x,int y);
int find(int c);
int ask(int x,int y);
int main ()
{
    int x,y;
    cin >> n>>m >>p;
    for(int i = 0;i<n+1;i++)
    {
        a[i] = i;
        s[i] = 1;
    }
    for(int i = 0;i<m;i++)
    {
        cin>> x>> y;
        link(x,y);
    }
    for(int i = 0;i<p;i++)
    {
        cin >> x>> y;
        ask(x,y);
    }
}
int link(int x,int y)
{
    int fx = find(x),fy = find(y);
    if(s[fx] > s[fy]){
        a[fy] = fx;
    }else if(s[fx] < s[fy]){
        a[fx] = fy;
    }else{
        a[fy] = fx;
        s[fx] ++;
    }
    return 0;
}
int find(int c)
{
    if(a[c] == c)
    {
        return c;
    }else{
        return a[c] = find(a[c]);
    }
}
int ask(int x,int y)
{
    if(find(x) == find(y)){
        cout<< "Yes"<<endl;
        return 1;
    }
    cout<<"No" << endl;
    return 0;
}