#include <bits/stdc++.h>

using namespace std;

const int M=(1<<18);

int n,m; //
int i,nr,mask,nmask;
int ans[19]; //
long long sum[19]; //
int adj[19]; //
long long dp[19][19][M]; //
bool fol[19][19][M]; //
vector<int> adjv[19]; //
vector<int> topo; //

int ind[19];
queue<int> q;

void bfs()
{
    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        topo.push_back(x);
        for(int it : adjv[x])
        {
            ind[it]--;
            if(!ind[it])
                q.push(it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        sum[x]+=c;
        sum[y]-=c;
        adj[x]+=1<<y;
        adjv[x].push_back(y);
        ind[y]++;
    }

    for(i=0;i<n;i++)
        if(!ind[i])
            q.push(i);
    bfs();

    for(nr=0;nr<=n;nr++)
        for(i=0;i<=n;i++)
            for(mask=0;mask<(1<<n);mask++)
                dp[nr][i][mask]=1e18;
    dp[0][0][0]=0;

    for(nr=0;nr<n;nr++)
        for(i=0;i<=n;i++)
            for(mask=0;mask<(1<<n);mask++)
            {
                if(i==n)
                {
                    if(dp[nr+1][0][mask] > dp[nr][i][mask])
                    {
                        dp[nr+1][0][mask]=dp[nr][i][mask];
                        fol[nr+1][0][mask]=false;
                    }
                }
                else
                {
                    int x=topo[i];
                    long long add=sum[x]*nr;

                    if(dp[nr][i+1][mask] > dp[nr][i][mask])
                    {
                        dp[nr][i+1][mask]=dp[nr][i][mask];
                        fol[nr][i+1][mask]=false;
                    }

                    if(!((mask>>x)&1) && (mask&adj[x])==adj[x])
                    {
                        nmask=mask+(1<<x);

                        if(dp[nr][i+1][nmask] > dp[nr][i][mask]+add)
                        {
                            dp[nr][i+1][nmask]=dp[nr][i][mask]+add;
                            fol[nr][i+1][nmask]=true;
                        }
                    }
                }
            }


    nr=n;
    i=0;
    mask=(1<<n)-1;

    while(nr>0 || i>0 || mask>0)
    {
        if(i==0)
        {
            i=n;
            nr--;
        }
        else
        {
            if(fol[nr][i][mask])
            {
                int x=topo[i-1];
                ans[x]=nr;
                mask-=(1<<x);
            }
            i--;
        }
    }

    for(i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
