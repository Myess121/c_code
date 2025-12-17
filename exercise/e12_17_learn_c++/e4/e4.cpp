#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int a,int b){
        return a>b;
    }
};
priority_queue <int,vector<int>,cmp>s;
int main()
{
    int n,cnt = 0,a,i,x,y;
    cin >> n;
    for(i = 0;i<n;i++)
    {
        cin >> a;
        s.push(a);
    }
    while(s.size() != 1)
    {
        x = s.top();
        s.pop();
        y = s.top();
        s.pop();
        cnt += x + y;
        s.push(x+y);
    }
    cout<<cnt<<endl;
    return 0;
}