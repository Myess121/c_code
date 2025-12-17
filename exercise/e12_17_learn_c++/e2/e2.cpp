#include <bits/stdc++.h>
using namespace std;
stack <char>a;
int main()
{
    string s;
    int n,k;
    scanf("%d",&n);
    while(n>0)
    {
        cin>>s;
        k = s.length()-1;
        while(k>=0)
        {
            if(a.empty()||a.top()!=s[k])
            {
                a.push(s[k]);
            }else{
                a.pop();
                if(s[k] == 'o'&&a.empty()){
                    a.push('O');
                }else{
                    a.pop();
                }
            }
            k--;
        }
        while(~a.empty()){
            cout << a.top();
            a.pop();
        }
        cout << endl;
        n--;
    }
    return 0;
}