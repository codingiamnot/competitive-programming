#include <bits/stdc++.h>

using namespace std;
int n,i,a[200005],b[200005],v[200005];
long long ans;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
        cin>>b[i];

    for(i=1;i<=n;i++)
        v[i]=a[i]-b[i];

    sort(v+1, v+n+1);

    for(i=1;i<n;i++)
    {
        auto poz = upper_bound(v+i+1, v+n+1, -v[i]);
        ans+=v+n+1-poz;
    }
    cout<<ans;
    return 0;
}
