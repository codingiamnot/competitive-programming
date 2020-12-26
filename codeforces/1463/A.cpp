#include <bits/stdc++.h>

using namespace std;

long long t,a,b,c,sum;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>c;

        sum=a+b+c;

        if(sum%9)
        {
            cout<<"NO\n";
            continue;
        }

        if(sum/9 > min({a, b, c}))
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
    }
    return 0;
}
