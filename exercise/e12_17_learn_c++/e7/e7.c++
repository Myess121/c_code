#include <bits/stdc++.h>
using namespace std;
int a[500005],n,m,cnt = 0,maxx ;

int main()
{
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0;i<m ;i++)
    {
        cnt += a[i];
    }
    maxx = cnt;
    for(int i = m;i<n;i++)
    {
        cnt -= a[i-m];
        cnt += a[i];
        if(cnt > maxx)
        {
            maxx = cnt;
        } 
    }
    cout << maxx << endl;
    return 0;
}