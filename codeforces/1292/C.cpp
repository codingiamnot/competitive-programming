#include <bits/stdc++.h>

using namespace std;
int n,i,j,x,y;
long long ans;
vector<int> adj[3005];
int par[3005][3005];
long long sz[3005][3005];
long long dp[3005][3005];
void dfs(int p, int last)
{
    par[i][p]=last;
    sz[i][p]=1;

    for(int it : adj[p])
        if(it!=last)
        {
            dfs(it, p);
            sz[i][p]+=sz[i][it];
        }
}
void calc(int x, int y)
{
    if(dp[x][y]!=-1)
        return;
    if(x==y)
    {
        dp[x][y]=0;
        return;
    }

    calc(par[y][x], y);
    calc(x, par[x][y]);

    dp[x][y]=sz[x][y]*sz[y][x]+max(dp[par[y][x]][y], dp[x][par[x][y]]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(i=1;i<=n;i++)
        dfs(i, 0);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dp[i][j]=-1;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            calc(i, j);
            ans=max(ans, dp[i][j]);
        }

    cout<<ans;
    return 0;
}
