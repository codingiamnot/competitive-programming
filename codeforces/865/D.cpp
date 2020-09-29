#include <bits/stdc++.h>

using namespace std;
int n,i;
long long ans;
int a[300005];
multiset <int> s;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    ans=0;
    for(i=1;i<=n;i++)
    {
        if(!s.empty() && a[i]>*s.begin())
        {
            ans+=a[i]-*s.begin();
            s.erase(s.begin());
            s.insert(a[i]);
        }

        s.insert(a[i]);
    }

    cout<<ans;
    return 0;
}
