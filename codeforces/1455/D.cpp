#include <bits/stdc++.h>

using namespace std;
int t,n,x,ans;
int i,lval,cx;
int a[505];
int dp[505][505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>x;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=0;i<=n;i++)
            for(cx=0;cx<=500;cx++)
                for(lval=0;lval<=500;lval++)
                    dp[i][cx][lval]=1e9;

        dp[0][x][0]=0;

        for(i=1;i<=n;i++)
        {
            for(cx=0;cx<=500;cx++)
                for(lval=0;lval<=a[i];lval++)
                    dp[i][cx][a[i]]=min(dp[i][cx][a[i]], dp[i-1][cx][lval]);

            for(cx=0;cx<=a[i];cx++)
            {
                for(lval=0;lval<=cx;lval++)
                {
                    dp[i][a[i]][cx]=min(dp[i][a[i]][cx], dp[i-1][cx][lval]+1);
                }
            }
        }

        ans=1e9;
        for(cx=0;cx<=500;cx++)
            for(lval=0;lval<=500;lval++)
                ans=min(ans, dp[n][cx][lval]);

        if(ans==1e9)
            cout<<"-1\n";
        else
            cout<<ans<<'\n';
    }
    return 0;
}
