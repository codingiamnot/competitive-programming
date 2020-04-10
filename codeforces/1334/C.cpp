#include <bits/stdc++.h>

using namespace std;
int t,n,i;
long long sum,ans;
long long a[300005];
long long b[300005];
long long cost[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        sum=0;
        for(i=1;i<=n;i++)
            cin>>a[i]>>b[i];

        for(i=1;i<=n;i++)
        {
            if(i==1)
                cost[i]=max((long long)0, a[1]-b[n]);
            else
                cost[i]=max((long long)0, a[i]-b[i-1]);

            sum+=cost[i];
        }

        ans = sum-cost[1]+a[1];

        for(i=2;i<=n;i++)
            ans=min(ans, sum-cost[i]+a[i]);

        cout<<ans<<'\n';
    }
    return 0;
}
