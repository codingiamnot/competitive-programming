#include <iostream>
#define mod 1000000007

using namespace std;
int n,a,b,k;
int pas,i,dist;
long long sum,ans;
long long dp[5005][5005];
int main()
{
    cin>>n>>a>>b>>k;
    dp[0][a]=1;
    dp[0][a+1]=-1;
    for(pas=0;pas<=k;pas++)
    {
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=dp[pas][i];
            if(sum<0)
                sum+=mod;
            sum%=mod;
            dp[pas][i]=sum;
        }

        for(i=1;i<=n;i++)
        {
            if(i==b)
                continue;

            if(i<b)
            {
                dist=b-i;

                dp[pas+1][i+1]+=dp[pas][i];
                dp[pas+1][b]-=dp[pas][i];

                dp[pas+1][max(i-dist+1, 1)]+=dp[pas][i];
                dp[pas+1][i]-=dp[pas][i];
            }
            else
            {
                dist=i-b;

                dp[pas+1][b+1]+=dp[pas][i];
                dp[pas+1][i]-=dp[pas][i];

                dp[pas+1][i+1]+=dp[pas][i];
                dp[pas+1][min(i+dist, n+1)]-=dp[pas][i];
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        ans+=dp[k][i];
        ans%=mod;
    }


    cout<<ans;
    return 0;
}
