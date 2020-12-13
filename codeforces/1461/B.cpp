#include <bits/stdc++.h>

using namespace std;

int t,n,m,i,j,ans;
int dp[505][505];
char a[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>a[i][j];

        for(i=1;i<=n+1;i++)
            for(j=1;j<=m+1;j++)
                dp[i][j]=0;

        ans=0;
        for(i=n;i>=1;i--)
            for(j=1;j<=m;j++)
            {
                if(a[i][j]=='*')
                {
                    dp[i][j]=min({dp[i+1][j], dp[i+1][j-1], dp[i+1][j+1]})+1;
                    ans+=dp[i][j];
                }

                else
                    dp[i][j]=0;
            }

        cout<<ans<<'\n';
    }
    return 0;
}
