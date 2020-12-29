#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct pos
{
    int x, r, f;
    bool operator<(pos b) const
    {
        return r<b.r;
    }
};
struct nod
{
    pair<int, int> val;
    long long ran;
    int cnt;

    nod *l, *r;

    nod(pair<int, int> x)
    {
        val=x;
        cnt=1;
        ran=rng();

        l=r=0;
    }
};

int n,k,i,j;
long long ans;
nod *m[20005];
pos v[100005];

void upd(nod *p)
{
    p->cnt=1;

    if(p->l)
        p->cnt+=p->l->cnt;

    if(p->r)
        p->cnt+=p->r->cnt;
}
void split(nod *p, nod *&l, nod *&r, pair<int, int> x)
{
    if(!p)
    {
        l=r=0;
        return;
    }

    if(p->val<=x)
    {
        l=p;
        split(p->r, p->r, r, x);
    }
    else
    {
        r=p;
        split(p->l, l, p->l, x);
    }

    upd(p);
}
void fmerge(nod *&p, nod *l, nod *r)
{
    if(!l)
    {
        p=r;
        return;
    }
    if(!r)
    {
        p=l;
        return;
    }

    if(l->ran > r->ran)
    {
        p=l;
        fmerge(p->r, p->r, r);
    }
    else
    {
        p=r;
        fmerge(p->l, l, p->l);
    }
    
    upd(p);
}

void add(nod *&p, pair<int, int> x)
{
    nod *l, *mij, *r;

    split(p, l, mij, {x.first, x.second-1});
    split(mij, mij, r, x);

    mij=new nod(x);

    fmerge(p, l, mij);
    fmerge(p, p, r);
}
void del(nod *&p, pair<int, int> x)
{
    nod *l, *mij, *r;

    split(p, l, mij, {x.first, x.second-1});
    split(mij, mij, r, x);
    fmerge(p, l, r);
}

int query(nod *&p, int st, int dr)
{
    nod *l, *mij, *r;

    split(p, l, mij, {st-1, 1e9});
    split(mij, mij, r, {dr, 1e9});

    int ans=0;
    if(mij)
        ans=mij->cnt;

    fmerge(p, l, mij);
    fmerge(p, p, r);

    return ans;
}

int main()
{
    cin>>n>>k;

    for(i=1;i<=n;i++)
        cin>>v[i].x>>v[i].r>>v[i].f;

    sort(v+1, v+n+1);

    for(i=1;i<=n;i++)
        add(m[v[i].f], {v[i].x, i});

    for(i=1;i<=n;i++)
    {
        del(m[v[i].f], {v[i].x, i});

        for(j=max(0, v[i].f-k);j<=v[i].f+k;j++)
            ans+=query(m[j], v[i].x-v[i].r, v[i].x+v[i].r);
    }

    cout<<ans;
    return 0;
}
