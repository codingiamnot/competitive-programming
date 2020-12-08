#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    int coef, adj, in;
    vector<int> v;
};

int n,m,i,j,x,y,w,mask;
nodS nod[22];
int dp[20][20][300005];
int last[20][20][300005];
int ans[22];

void recon(int i, int j, int mask)
{
    if(!mask)
        return;

    int li=i;
    int lj=j-1;

    if(lj<0)
    {
        lj=n-1;
        li--;
    }

    if(last[i][j][mask]==-1)
    {
        recon(li, lj, mask);
    }
    else
    {
        int it=last[i][j][mask];
        ans[it]=i;

        recon(li, lj, mask-(1<<it));
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        x--;
        y--;

        nod[x].coef+=w;
        nod[y].coef-=w;

        nod[x].v.push_back(y);
        nod[x].adj+=(1<<y);

        nod[y].in++;
    }

    queue<int> q;
    vector<int> topo;
    for(i=0;i<n;i++)
    {
        if(!nod[i].in)
            q.push(i);
    }

    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        topo.push_back(p);

        for(int it : nod[p].v)
        {
            nod[it].in--;
            if(!nod[it].in)
                q.push(it);
        }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(mask=1;mask<(1<<n);mask++)
                dp[i][j][mask]=1e9;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            int li=i;
            int lj=j-1;

            if(lj<0)
            {
                lj=n-1;
                li--;
            }

            if(li<0)
            {
                li=0;
                lj=0;
            }

            for(mask=0;mask<(1<<n);mask++)
            {
                dp[i][j][mask]=dp[li][lj][mask];
                last[i][j][mask]=-1;

                int it=topo[j];

                if(((mask>>it)&1)==0)
                    continue;

                if((mask&nod[it].adj) != nod[it].adj)
                    continue;

                if(dp[i][j][mask] > dp[li][lj][mask-(1<<it)]+i*nod[it].coef)
                {
                    dp[i][j][mask]=dp[li][lj][mask-(1<<it)]+i*nod[it].coef;
                    last[i][j][mask]=it;
                }
            }
        }
    }

    //cout<<dp[n-1][n-1][(1<<n)-1];

    recon(n-1, n-1, (1<<n)-1);

    for(i=0;i<n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
