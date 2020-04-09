#include <iostream>

using namespace std;
int n,m,i,st,stmax,drmax;
long long a[300005];
long long sum,maxi,ans;
long long dpl[300005];
long long dpr[300005];
long long dp[300005];
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        cin>>a[i];

    if(m>0)
    {
        for(i=1; i<=n; i++)
        {
            sum+=a[i];
            if(sum<0)
            {
                sum=0;
                continue;
            }

            maxi=max(maxi, sum);
        }

        cout<<maxi*m;
        return 0;
    }

    for(i=1;i<=n;i++)
        dpl[i]=max((long long)0, a[i]+max((long long)0, dpl[i-1]));

    for(i=n;i>=1;i--)
        dpr[i]=max((long long)0, a[i]+max((long long)0, dpr[i+1]));

    for(i=1;i<=n;i++)
    {
        dp[i]=dpl[i]+dpr[i+1];
        dp[i]=max(dp[i], a[i]*m+dpl[i-1]+dpr[i+1]);
        dp[i]=max(dp[i], dp[i-1]+a[i]*m-dpr[i]+dpr[i+1]);
    }

    for(i=1;i<=n;i++)
        ans=max(ans, dp[i]);
    cout<<ans;
    return 0;
}
