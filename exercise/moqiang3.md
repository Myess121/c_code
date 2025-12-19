## 逆序对
```cpp
#include<cstdio>
#include<iostream>
using namespace std;
int n,a[500010],c[500010];
long long ans;

void msort(int b,int e)//归并排序
{
    if(b==e)  
		return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    msort(b,mid),msort(mid+1,e);
    while(i<=mid&&j<=e)
    	if(a[i]<=a[j])
    		c[k++]=a[i++];
    	else
    		c[k++]=a[j++],ans+=mid-i+1;//统计答案
    while(i<=mid)
    	c[k++]=a[i++];
    while(j<=e)
    	c[k++]=a[j++];
    for(int l=b;l<=e;l++)
    	a[l]=c[l];
} 

int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
    	scanf("%d",&a[i]);
    msort(1,n);
    printf("%lld",ans);
    return 0;
}
```

## 切蛋糕
```cpp
#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<deque>
#define debug cout<<"ok"<<endl
typedef long long ll;
const int maxn=1e7+10;
const int mod=1e9+7;
using namespace std;
int ans=-233333333,n,m,a,sum[maxn];
deque<int>q;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        sum[i]=sum[i-1]+a;//前缀和
    }
    q.push_back(0);//赋初值
    for(int i=1;i<=n;i++)
    {
        while(q.front()+m<i)
            q.pop_front();//越界就pop
        ans=max(ans,sum[i]-sum[q.front()]);
        while(!q.empty()&&sum[q.back()]>=sum[i])//递减就pop
            q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",ans);
    return 0;
}
```
##st表
```cpp
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int N=1005;
int LOG[N],bin[15],n,m,a[N],x,y;
int f[N][10];
int gcd(int i,int j)
{
    return !j?i:gcd(j,i%j);
}
int main ()
{
    scanf ("%d%d",&n,&m);
    bin[0]=1;for (int i=1;i<=10;++i)bin[i]=bin[i-1]<<1;
    LOG[0]=-1;for (int i=1;i<=n;++i)LOG[i]=LOG[i>>1]+1;
    for (int i=1;i<=n;++i)scanf ("%d",&f[i][0]);
    for (int i=1;i<=10;++i)
        for (int j=1;j+bin[i]-1<=n;++j)
            f[j][i]=gcd(f[j][i-1],f[j+bin[i-1]][i-1]);
    for (int i=1;i<=m;++i)
    {
        scanf ("%d%d",&x,&y);
        int lo=LOG[y-x+1];
        printf ("%d\n",gcd(f[x][lo],f[y-bin[lo]+1][lo]));//防止不是2的正整数幂时没有包括到
    }
    return 0;
}
```

## 栈
```cpp
#include <iostream>
#include <stack>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//代码预处理区

stack<char> st, tmp;
//全局变量区

int main() {
    IOS;
    string s; 
    while (cin >> s) {
        int len = s.length();
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (st.empty()) {
                st.push(ch);
                continue;
            }             char top = st.top();
            bool flag = 0;//表示不是炸裂开的
            while (ch == top) {
                if ('o' == ch) {
                    st.pop();
                    ch = 'O';
                }
                else {
                    st.pop();
                    flag = 1;
                    break;
                }
                if (st.empty()) break;
                top = st.top();
            }
            if (!flag) st.push(ch);
        }
        while (!st.empty()) {
            tmp.push(st.top());
            st.pop();
        }
        while (!tmp.empty()) {
            cout << tmp.top();
            tmp.pop();
        }
        cout << endl;
    }
    return 0;
}

```