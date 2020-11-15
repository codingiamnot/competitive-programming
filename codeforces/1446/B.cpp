#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,ans;
int dp[5005][5005];
char a[5005],b[5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=m;i++)
        cin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=2+max(0, dp[i-1][j-1]);
            }
            else
            {
                dp[i][j]=-1+max(0, max(dp[i-1][j], dp[i][j-1]));
            }

            ans=max(ans, dp[i][j]);
        }

    cout<<ans;
    return 0;
}
