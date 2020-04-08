#include <bits/stdc++.h>

using namespace std;
int n,i;
long long ans;
int minip[200005];
int minit[200005];
long long a[200005];
long long s[200005];
map <long long, set<int>> m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        m[s[i]].insert(i);
    }

    for(i=1;i<=n;i++)
    {
        if(m[s[i-1]].empty())
            minip[i]=n+1;
        else
            minip[i]=*m[s[i-1]].begin();

        m[s[i]].erase(i);
    }

    minit[n]=minip[n];
    for(i=n-1;i>=1;i--)
        minit[i]=min(minip[i], minit[i+1]);

    for(i=1;i<=n;i++)
        ans+=minit[i]-i;

    cout<<ans;
    return 0;
}
