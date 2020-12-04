#include <bits/stdc++.h>

using namespace std;

long long t,ans,maxi,n,i;
long long a[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        ans=0;
        maxi=0;

        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=2;i<=n;i++)
            ans+=abs(a[i]-a[i-1]);

        maxi=max(maxi, abs(a[2]-a[1]));
        maxi=max(maxi, abs(a[n]-a[n-1]));

        for(i=2;i<n;i++)
            maxi=max(maxi, abs(a[i]-a[i-1])+abs(a[i+1]-a[i])-abs(a[i+1]-a[i-1]));

        cout<<ans-maxi<<'\n';
    }
    return 0;
}
