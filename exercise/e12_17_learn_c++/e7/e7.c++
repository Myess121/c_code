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
    for(int j = 0;j<m;j++)
    {   
        cnt =0 ;
        for(int i = 0;i<m-j ;i++)
        {
            cnt += a[i];
        }
        if(cnt > maxx)
            {
                maxx = cnt;
            }
        for(int i = m-j;i<n;i++)
        {
            cnt -= a[i-m+j];
            cnt += a[i];
            if(cnt > maxx)
            {
                maxx = cnt;
            } 
        }
    }
    
    cout << maxx << endl;
    return 0;
}