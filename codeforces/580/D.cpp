#include <iostream>

using namespace std;
int n,m,k;
int x,y,cost;
int i,mask,last,nex;
long long v[20];
long long c[20][20];
long long dp[500005][20];
long long ans;
int cnt(int mask)
{
    int ans=0;
    for(int b=0;b<n;b++)
        if(((mask>>b)&1) == 1)
            ans++;

    return ans;
}
int main()
{
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        cin>>v[i];
    for(i=1;i<=k;i++)
    {
        cin>>x>>y>>cost;
        x--;
        y--;
        c[x][y]=cost;
    }

    for(last=0;last<n;last++)
    {
        dp[(1<<last)][last]=v[last];
    }

    for(mask=0;mask<(1<<n);mask++)
    {
        for(last=0;last<n;last++)
        {
            if(((mask>>last)&1) == 0)
                continue;

            for(nex=0;nex<n;nex++)
            {
                if(((mask>>nex)&1) == 1)
                    continue;

                dp[mask+(1<<nex)][nex]=max(dp[mask+(1<<nex)][nex], dp[mask][last]+c[last][nex]+v[nex]);
            }
        }
    }

    for(mask=0;mask<(1<<n);mask++)
    {
        if(cnt(mask)==m)
        {
            for(last=0;last<n;last++)
            {
                if(((mask>>last)&1) == 0)
                    continue;

                ans=max(ans, dp[mask][last]);
            }
        }
    }

    cout<<ans;
    return 0;
}
