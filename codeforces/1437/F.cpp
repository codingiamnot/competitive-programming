#include <bits/stdc++.h>
#define mod 998244353

using namespace std;

long long n,i,p,j;
long long a[5005];
long long dp[5005][5005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1, a+n+1);

    dp[0][0]=1;

    p=0;
    for(i=1;i<=n;i++)
    {
        while(a[p+1]*2<=a[i])
            p++;

        for(j=1;j<=p+1;j++)
        {
            if(j>1)
            {
                dp[i][j]+=(dp[i][j-1]*(p-j+2))%mod;
                dp[i][j]%=mod;
            }

            dp[i][j]+=dp[p][j-1];
            dp[i][j]%=mod;
        }

        for(j=0;j<=p+1;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
        }
    }

    cout<<dp[n][n];
    return 0;
}
