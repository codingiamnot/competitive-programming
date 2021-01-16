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

long long n,i,j,x,ans;
long long a[3005];
long long fr[105];

int main()
{
    cin>>n;

    dinic g=dinic(n+2, n+1, n+2);

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        memset(fr, 0, sizeof fr);

        for(j=i-1;j>=1;j--)
        {
            if(a[i]%a[j]==0 && !fr[a[j]])
            {
                fr[a[j]]++;
                g.add_edge(i, j, 1e9);
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        cin>>x;
        ans+=max(x, (long long)0);

        if(x>=0)
            g.add_edge(n+1, i, x);
        else
            g.add_edge(i, n+2, -x);
    }

    cout<<ans-g.flow();
    return 0;
}
