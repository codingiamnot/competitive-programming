#include <bits/stdc++.h>

using namespace std;
long long t,n,k,i,maxi,mini,maxp,minp,ans;
long long a[200005];
vector<long long> v;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        for(i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1, a+n+1);

        ans=0;
        for(i=n;i>=n-k;i--)
            ans+=a[i];
        cout<<ans<<'\n';
    }
    return 0;
}
