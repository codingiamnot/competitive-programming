#include <bits/stdc++.h>

using namespace std;
int n,k,i;
long long a[200005];
long long dpl[200005];
long long dpr[200005];
long long ans;
map <int, long long> m;
int main()
{
    cin>>n>>k;
    if(k==1)
    {
        cout<<0;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }

    for(auto it : m)
    {
        if(it.second>=k)
        {
            cout<<0;
            return 0;
        }
    }

    sort(a+1, a+n+1);

    dpl[1]=0;
    for(i=2;i<=n;i++)
        dpl[i]=dpl[i-1]+(i-1)*(a[i]-a[i-1]);

    dpr[n]=0;
    for(i=n-1;i>=1;i--)
        dpr[i]=dpr[i+1]+(n-i)*(a[i+1]-a[i]);

    ans=dpl[n];
    for(i=1;i<=n;i++)
    {
        if(i>=k)
            ans=min(ans, dpl[i]-(i-k));
        if(n-i+1>=k)
            ans=min(ans, dpr[i]-(n-i+1-k));

        ans=min(ans, dpl[i]+dpr[i]-(n-k));
    }
    ans=max(ans, (long long)0);
    cout<<ans;
    return 0;
}
