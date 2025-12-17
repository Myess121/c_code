#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,k,i;
    
    scanf("%d %d",&n,&k);
    vector<int>a(n);
    for(i= 1;i<=n;i++)
    {
        a[i-1] = i;
    }
    i = 0;
    while(a.size() > 1)
    {
        i = i+k-1;
        i %= n;
        a.erase(a.begin() + i );
        n --;
    }
    printf("%d\n",a[0]);

    return 0;
}