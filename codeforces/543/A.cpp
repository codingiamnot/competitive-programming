#include <iostream>

using namespace std;
int n,m,b,mod,p,cod,bug;
int a[505];
int dp[2][505][505];
long long ans;
int main()
{
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    dp[1][0][0]=1;
    for(p=1;p<=n;p++)
    {
        for(cod=0;cod<=m;cod++)
            for(bug=0;bug<=b;bug++)
            {
                dp[0][cod][bug]=dp[1][cod][bug];
                dp[1][cod][bug]=0;
            }


        for(cod=0;cod<=m;cod++)
        {
            for(bug=0;bug<=b;bug++)
            {
                dp[1][cod][bug]=dp[0][cod][bug];

                if(bug>=a[p])
                {
                    dp[1][cod][bug]+=dp[1][cod-1][bug-a[p]];
                    dp[1][cod][bug]%=mod;
                }
            }
        }
    }

    for(bug=0;bug<=b;bug++)
    {
        ans+=dp[1][m][bug];
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
