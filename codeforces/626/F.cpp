#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long n,k,i,nr,t,ans;
long long a[205];
long long dp[2][205][1005];

int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);

    dp[1][0][0]=1;
    a[0]=a[1];

    for(i=1;i<=n;i++)
    {
        for(nr=0;nr<=n;nr++)
            for(t=0;t<=k;t++)
            {
                dp[0][nr][t]=dp[1][nr][t];
                dp[1][nr][t]=0;
            }

        for(nr=0;nr<=n;nr++)
            for(t=0;t<=k;t++)
            {
                if(t>=nr*(a[i]-a[i-1]))
                {
                    ///singur
                    dp[1][nr][t]+=dp[0][nr][t-nr*(a[i]-a[i-1])];
                    dp[1][nr][t]%=mod;

                    ///intra intr-o grupa la mij
                    dp[1][nr][t]+=(dp[0][nr][t-nr*(a[i]-a[i-1])]*nr)%mod;
                    dp[1][nr][t]%=mod;
                }

                if(t>=(nr-1)*(a[i]-a[i-1]) && nr>=1)
                {
                    ///incepe o grupa
                    dp[1][nr][t]+=dp[0][nr-1][t-(nr-1)*(a[i]-a[i-1])];
                    dp[1][nr][t]%=mod;
                }

                if(t>=(nr+1)*(a[i]-a[i-1]))
                {
                    ///termina o grupa
                    dp[1][nr][t]+=(dp[0][nr+1][t-(nr+1)*(a[i]-a[i-1])]*(nr+1))%mod;
                    dp[1][nr][t]%=mod;
                }
            }
    }

    ans=0;
    for(t=0;t<=k;t++)
    {
        ans+=dp[1][0][t];
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
