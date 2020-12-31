#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct nod
{
    int x, sz;
    int ran;
    bool rev;
    nod *l, *r;

    nod(int x)
    {
        this->x=x;
        rev=false;
        sz=1;

        ran=rng();

        l=r=0;
    }
};

void push(nod *p)
{
    if(!p->rev)
        return;

    p->rev=false;

    if(p->l)
        p->l->rev^=1;
    if(p->r)
        p->r->rev^=1;

    swap(p->l, p->r);
}
void upd(nod *p)
{
    p->sz=1;
    if(p->l)
        p->sz+=p->l->sz;
    if(p->r)
        p->sz+=p->r->sz;
}
void split(nod *p, nod *&l, nod *&r, int x)
{
    if(!p)
    {
        l=r=0;
        return;
    }

    push(p);

    int i=1;
    if(p->l)
        i+=p->l->sz;

    if(i<=x)
    {
        l=p;
        split(p->r, p->r, r, x-i);
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

    push(l);
    push(r);

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
void add(nod *&p, int x, int i)
{
    nod *l,*mij,*r;

    split(p, l, r, i-1);
    mij=new nod(x);
    fmerge(p, l, mij);
    fmerge(p, p, r);
}
void del(nod *&p, int i)
{
    nod *l,*mij,*r;

    split(p, l, mij, i-1);
    split(mij, mij, r, 1);
    fmerge(p, l, r);
}
int query(nod *&p, int i)
{
    nod *l,*mij,*r;

    split(p, l, mij, i-1);
    split(mij, mij, r, 1);

    int ans=mij->x;

    fmerge(p, l, mij);
    fmerge(p, p, r);

    return ans;
}
void rev(nod *&p, int st, int dr)
{
    nod *l,*mij,*r;

    split(p, l, mij, st-1);
    split(mij, mij, r, dr-st+1);

    mij->rev^=1;

    fmerge(p, l, mij);
    fmerge(p, p, r);
}

int n,q,m,i,x,t,l,r;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    nod *root=0;

    cin>>n>>q>>m;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        add(root, x, i);
    }

    while(q)
    {
        q--;
        cin>>t>>l>>r;

        if(t==1)
        {
            x=query(root, r);
            del(root, r);
            add(root, x, l);
        }
        else
        {
            rev(root, l, r);
        }
    }

    while(m)
    {
        m--;
        cin>>x;
        cout<<query(root, x)<<' ';
    }
    return 0;
}
