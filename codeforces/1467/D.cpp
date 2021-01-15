#include <iostream>
#define mod 1000000007

using namespace std;

long long n,k,q,i,j,x,p,ans;
long long dp[5005][5005];
long long coef[5005];
long long a[5005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k>>q;

    for(i=1;i<=n;i++)
        dp[i][0]=1;

    for(j=1;j<=k;j++)
        for(i=1;i<=n;i++)
            dp[i][j]=(dp[i-1][j-1]+dp[i+1][j-1])%mod;

    for(j=0;j<=k;j++)
        for(i=1;i<=n;i++)
        {
            coef[i]+=(dp[i][j]*dp[i][k-j])%mod;
            coef[i]%=mod;
        }

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        ans+=(coef[i]*a[i])%mod;
        ans%=mod;
    }

    while(q)
    {
        q--;
        cin>>p>>x;
        ans-=(coef[p]*a[p])%mod;
        if(ans<0)
            ans+=mod;

        a[p]=x;
        ans+=(coef[p]*a[p])%mod;
        ans%=mod;

        cout<<ans<<'\n';
    }
    return 0;
}
