#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct nod
{
    long long ran;
    long long val,sum,cnt,ans;
    nod *l, *r;

    nod(int x)
    {
        val=x;
        sum=x;
        cnt=1;
        ans=0;

        ran=rng();

        l=0;
        r=0;
    }
};

void upd(nod *p)
{
    p->sum=p->val;
    p->cnt=1;
    p->ans=0;

    if(p->l)
    {
        p->cnt+=p->l->cnt;
        p->sum+=p->l->sum;
        p->ans+=p->l->ans;

        p->ans+= p->l->cnt*p->val - p->l->sum;
    }

    if(p->r)
    {
        p->cnt+=p->r->cnt;
        p->sum+=p->r->sum;
        p->ans+=p->r->ans;

        p->ans+= p->r->sum - p->r->cnt*p->val;
    }

    if(p->l && p->r)
    {
        p->ans+= p->l->cnt*p->r->sum - p->r->cnt*p->l->sum;
    }
}
void split(nod *p, nod *&l, nod *&r, int val)
{
    if(!p)
    {
        l=r=0;
        return;
    }

    if(p->val<=val)
    {
        l=p;
        split(p->r, p->r, r, val);
    }
    else
    {
        r=p;
        split(p->l, l, p->l, val);
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
void add(nod *&p, int x)
{
    nod *l, *mij, *r;

    split(p, l, r, x-1);
    split(r, mij, r, x);

    mij=new nod(x);

    fmerge(p, l, mij);
    fmerge(p, p, r);
}
void del(nod *&p, int x)
{
    nod *l, *mij, *r;

    split(p, l, r, x-1);
    split(r, mij, r, x);
    fmerge(p, l, r);
}
long long query(nod *& p, int st, int dr)
{
    nod *l, *mij, *r;

    split(p, l, r, st-1);
    split(r, mij, r, dr);

    long long ans=0;
    if(mij)
        ans=mij->ans;

    fmerge(p, l, mij);
    fmerge(p, p, r);

    return ans;
}

int n,i,m,t,p,d,l,r;
int a[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    nod *root=0;

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        add(root, a[i]);
    }

    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>t;

        if(t==1)
        {
            cin>>p>>d;

            del(root, a[p]);
            a[p]+=d;
            add(root, a[p]);
        }
        else
        {
            cin>>l>>r;

            cout<<query(root, l, r)<<'\n';
        }
    }
    return 0;
}
