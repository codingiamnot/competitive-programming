#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    int d,dp;
    vector<int> v;
};

int t,n,m,x,y,i;
nodS nod[200005];

void bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 0});

    while(!q.empty())
    {
        int p=q.front().first;
        int len=q.front().second;
        q.pop();

        if(nod[p].d!=-1)
            continue;

        nod[p].d=len;

        for(int it : nod[p].v)
            q.push({it, len+1});
    }
}
void dfs(int p)
{
    if(nod[p].dp)
        return;

    nod[p].dp=nod[p].d;

    for(int it : nod[p].v)
    {
        if(nod[it].d<=nod[p].d)
            nod[p].dp=min(nod[p].dp, nod[it].d);
        else
        {
            dfs(it);
            nod[p].dp=min(nod[p].dp, nod[it].dp);
        }
    }
}
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
        {
            nod[i].v.clear();
            nod[i].d=-1;
            nod[i].dp=0;
        }

        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            nod[x].v.push_back(y);
        }

        bfs();
        dfs(1);

        for(i=1;i<=n;i++)
            cout<<nod[i].dp<<' ';
        cout<<'\n';
    }
    return 0;
}
