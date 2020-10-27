#include <bits/stdc++.h>

using namespace std;
int nrt,n,i,t,lt,ans;
int v[205];
int dp[205][405];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>nrt;
    while(nrt)
    {
        nrt--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>v[i];
        sort(v+1, v+n+1);

        for(i=1;i<=n;i++)
            for(t=1;t<=2*n;t++)
                dp[i][t]=1e8;

        for(i=1;i<=n;i++)
            for(t=i;t<=2*n;t++)
            {
                for(lt=i-1;lt<t;lt++)
                    dp[i][t]=min(dp[i][t], dp[i-1][lt]+abs(t-v[i]));
            }

        ans=1e8;
        for(t=n;t<=2*n;t++)
            ans=min(ans, dp[n][t]);
        cout<<ans<<'\n';
    }
    return 0;
}
