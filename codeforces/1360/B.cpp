#include <bits/stdc++.h>

using namespace std;
long long t,n,ans,i;
long long a[55];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        ans=1e18;
        for(i=2;i<=n;i++)
            ans=min(ans, a[i]-a[i-1]);
        cout<<ans<<'\n';
    }
    return 0;
}
