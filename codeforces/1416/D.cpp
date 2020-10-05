#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
struct drum
{
    int x, y;
    bool del=false;
};
struct qs
{
    int t, v;
};
struct nodS
{
    int l, r;
    vector<int> v;
};
int n,m,q,i,t;
int val[200005];
int par[500005];
drum e[300005];
qs qv[500005];
nodS nod[500005];
vector<pair<int, int>> seg;

int dsu_par(int x)
{
    if(par[x]==x)
        return x;

    par[x]=dsu_par(par[x]);
    return par[x];
}
void dsu_merge(int x, int y)
{
    x=dsu_par(x);
    y=dsu_par(y);

    if(x==y)
        return;

    n++;
    par[x]=n;
    par[y]=n;

    nod[n].v.push_back(x);
    nod[n].v.push_back(y);
    par[n]=n;
}
void dfs(int p)
{
    nod[p].l=t;

    for(int it : nod[p].v)
    {
        dfs(it);
        t++;
    }
    if(!nod[p].v.empty())
        t--;

    nod[p].r=t;
}

void upd(int pos, int val, int st, int dr, int p)
{
    if(st==dr)
    {
        seg[p]={val, pos};
        return;
    }

    int mij=(st+dr)/2;

    if(pos<=mij)
        upd(pos, val, st, mij, 2*p);
    if(pos>mij)
        upd(pos, val, mij+1, dr, 2*p+1);

    seg[p]=max(seg[2*p], seg[2*p+1]);
}
pair<int, int> query(int stt, int drt, int st, int dr, int p)
{
    if(stt==st && drt==dr)
        return seg[p];

    int mij=(st+dr)/2;

    if(drt<=mij)
        return query(stt, drt, st, mij, 2*p);
    if(stt>mij)
        return query(stt, drt, mij+1, dr, 2*p+1);

    return max(query(stt, mij, st, mij, 2*p), query(mij+1, drt, mij+1, dr, 2*p+1));
}
int ans(int st, int dr)
{
    auto ans=query(st, dr, 1, n, 1);
    upd(ans.s, 0, 1, n, 1);
    return ans.f;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m>>q;
    seg.resize(4*n+4);
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
        par[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        cin>>e[i].x>>e[i].y;
    }
    for(i=1;i<=q;i++)
    {
        cin>>qv[i].t>>qv[i].v;
        if(qv[i].t==2)
            e[qv[i].v].del=true;
    }

    for(i=1;i<=m;i++)
    {
        if(!e[i].del)
            dsu_merge(e[i].x, e[i].y);
    }

    for(i=q;i>=1;i--)
    {
        if(qv[i].t==2)
            dsu_merge(e[qv[i].v].x, e[qv[i].v].y);
        else
            qv[i].v=dsu_par(qv[i].v);
    }

    for(i=1;i<=n;i++)
    {
        if(par[i]==i)
        {
            t++;
            dfs(i);
        }
    }

    for(i=1;i<=n;i++)
    {
        if(nod[i].l != nod[i].r)
            break;

        upd(nod[i].l, val[i], 1, n, 1);
    }

    for(i=1;i<=q;i++)
    {
        if(qv[i].t==1)
        {
            int id=qv[i].v;
            cout<<ans(nod[id].l, nod[id].r)<<'\n';
        }
    }
    return 0;
}
