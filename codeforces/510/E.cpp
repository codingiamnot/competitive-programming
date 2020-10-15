#include <bits/stdc++.h>

using namespace std;
struct edge
{
    int x, y;
    long long flow, cap;
    edge(int x, int y, long long cap)
    {
        this->x=x;
        this->y=y;
        this->cap=cap;
        this->flow=0;
    }
};
struct dinic
{
    const long long inf=1e18;
    vector<edge> e;
    vector<vector<int>> adj;
    vector<int> lvl, ptr;
    queue<int> q;
    int n, m=0, s, t;

    dinic(int n, int s, int t)
    {
        this->n=n;
        this->s=s;
        this->t=t;

        adj.resize(n+1);
        lvl.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int x, int y, long long cap)
    {
        e.push_back(edge(x, y, cap));
        e.push_back(edge(y, x, 0));
        adj[x].push_back(m);
        adj[y].push_back(m+1);
        m+=2;
    }

    bool bfs()
    {
        while(!q.empty())
        {
            int p=q.front();
            q.pop();

            for(int id : adj[p])
            {
                if(e[id].cap-e[id].flow <= 0)
                    continue;
                if(lvl[e[id].y] != -1)
                    continue;

                lvl[e[id].y]=lvl[p]+1;
                q.push(e[id].y);
            }
        }

        return lvl[t]!=-1;
    }

    long long dfs(int p, long long pushed)
    {
        if(!pushed)
            return 0;

        if(p==t)
            return pushed;

        for(int &i=ptr[p]; i< (int)adj[p].size(); i++)
        {
            int id=adj[p][i];
            int y=e[id].y;

            if(lvl[p]+1!=lvl[y] || e[id].cap-e[id].flow<=0)
                continue;

            long long npushed=dfs(y, min(pushed, e[id].cap-e[id].flow));

            if(!npushed)
                continue;

            e[id].flow+=npushed;
            e[id^1].flow-=npushed;
            return npushed;
        }

        return 0;
    }

    long long flow()
    {
        long long ans=0;

        while(true)
        {
            fill(lvl.begin(), lvl.end(), -1);
            lvl[s]=0;
            q.push(s);
            if(!bfs())
                break;

            fill(ptr.begin(), ptr.end(), 0);
            while(long long pushed=dfs(s, inf))
                ans+=pushed;
        }

        return ans;
    }
};
int n,i,j,nr;
int a[205];
int ciur[20005];
int viz[205];
vector<vector<int>> ans;
void genciur()
{
    for(int i=2;i<=2e4;i++)
    {
        if(!ciur[i])
        {
            for(int j=i*i;j<=2e4;j+=i)
                ciur[j]=1;
        }
    }
}
void dfs(int p, vector<int> &v, dinic &g)
{
    v.push_back(p);
    viz[p]=true;

    for(int it : g.adj[p])
    {
        if(g.e[it].flow && !viz[g.e[it].y] && g.e[it].y<=n)
            dfs(g.e[it].y, v, g);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    genciur();

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    dinic g=dinic(n+2, n+1, n+2);
    for(i=1;i<=n;i++)
    {
        if(a[i]%2)
            continue;

        for(j=1;j<=n;j++)
            if(!ciur[a[i]+a[j]])
                g.add_edge(i, j, 1);
    }

    for(i=1;i<=n;i++)
    {
        if(a[i]%2)
            g.add_edge(i, n+2, 2);
        else
            g.add_edge(n+1, i, 2);
    }

    nr=g.flow();

    if(nr!=n)
    {
        cout<<"Impossible";
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        if(!viz[i])
        {
            vector<int> v;
            dfs(i, v, g);
            ans.push_back(v);
        }
    }

    cout<<ans.size()<<'\n';
    for(auto it : ans)
    {
        cout<<it.size()<<' ';
        for(int it2 : it)
            cout<<it2<<' ';
        cout<<'\n';
    }
    return 0;
}
