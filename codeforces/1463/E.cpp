#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    int in, gr, ord;
    vector<int> v,g;
};
struct nodS2
{
    int in;
    bool on;
    vector<int> v, elem;
};

int n,m,nrg,rad;
int i,x,y;
int dsu[300005];
nodS nod[300005];
nodS2 nod2[300005];
vector<int> ans;
vector<int> ansf;

bool dfs(int p, int par)
{
    for(int it : nod[p].v)
    {
        if(it==p)
            continue;

        if(nod[p].ord>nod[it].ord)
            return false;

        if(!dfs(it, p))
            return false;
    }

    return true;
}

bool topo()
{
    queue<int> q;

    for(int i=1;i<=n;i++)
        if(!nod[i].in)
            q.push(i);

    int nr=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();

        if(nod[p].ord)
            continue;

        nr++;
        nod[p].ord=nr;

        for(int it : nod[p].g)
        {
            nod[it].in--;
            if(!nod[it].in)
                q.push(it);
        }
    }

    if(nr<n)
        return false;
    return true;
}
bool topo2()
{
    queue<int> q;

    for(int i=1;i<=nrg;i++)
    {
        if(!nod2[i].in)
            q.push(i);
    }

    while(!q.empty())
    {
        int p=q.front();
        q.pop();

        if(nod2[p].on)
            continue;

        nod2[p].on=true;
        ans.push_back(p);

        for(int it : nod2[p].v)
        {
            nod2[it].in--;

            if(!nod2[it].in)
                q.push(it);
        }
    }

    for(i=1;i<=nrg;i++)
        if(!nod2[i].on)
            return false;

    return true;
}

int dsu_par(int x)
{
    if(dsu[x]!=x)
        dsu[x]=dsu_par(dsu[x]);

    return dsu[x];
}
void dsu_merge(int x, int y)
{
    x=dsu_par(x);
    y=dsu_par(y);

    if(x!=y)
        dsu[x]=y;
}

bool comp(int x, int y)
{
    return nod[x].ord<nod[y].ord;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x;

        if(x)
            nod[x].v.push_back(i);
        else
            rad=i;
    }

    for(i=1;i<=n;i++)
        dsu[i]=i;

    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[x].g.push_back(y);
        nod[y].in++;
        dsu_merge(x, y);
    }

    if(!topo())
    {
        cout<<0;
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        int id=dsu_par(i);

        if(!nod[id].gr)
        {
            nrg++;
            nod[id].gr=nrg;
        }

        nod[i].gr=nod[id].gr;
    }

    /*
    for(i=1;i<=n;i++)
        cout<<nod[i].gr<<' ';
    cout<<'\n';
    */

    for(i=1;i<=n;i++)
    {
        int gr=nod[i].gr;

        nod2[gr].elem.push_back(i);

        for(int it : nod[i].v)
        {
            if(gr==nod[it].gr)
                continue;

            nod2[gr].v.push_back(nod[it].gr);
            nod2[nod[it].gr].in++;
        }
    }

    /*
    for(i=1;i<=nrg;i++)
    {
        cout<<"grupa "<<i<<'\n';

        for(int it : nod2[i].elem)
            cout<<it<<' ';
        cout<<'\n';

        for(int it : nod2[i].v)
            cout<<it<<' ';
        cout<<'\n';
    }
    */

    if(!topo2())
    {
        cout<<0;
        return 0;
    }

    for(int gr : ans)
    {
        sort(nod2[gr].elem.begin(), nod2[gr].elem.end(), comp);

        for(int it : nod2[gr].elem)
        {
            ansf.push_back(it);
            nod[it].ord=ansf.size();
        }
    }

    if(!dfs(rad, 0))
    {
        cout<<0;
        return 0;
    }

    for(int it : ansf)
    {
        cout<<it<<' ';
    }
    return 0;
}
