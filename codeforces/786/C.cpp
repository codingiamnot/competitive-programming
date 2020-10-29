#include <iostream>

using namespace std;
struct nodS
{
    int val=0;
    nodS *l, *r;
};
int n,i,k,p,ans;
int a[100005];
int last[100005];
nodS *v[100005];

nodS* build(int st, int dr)
{
    nodS *ans=new nodS();

    if(st!=dr)
    {
        int mij=(st+dr)/2;

        ans->l=build(st, mij);
        ans->r=build(mij+1, dr);
    }

    return ans;
}
nodS* updpers(int i, int st, int dr, nodS *p)
{
    nodS *ans=new nodS();

    if(st==dr)
    {
        ans->val = 1 - p->val;
        return ans;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
    {
        ans->l=updpers(i, st, mij, p->l);
        ans->r=p->r;
    }
    else
    {
        ans->l=p->l;
        ans->r=updpers(i, mij+1, dr, p->r);
    }

    ans->val=ans->l->val + ans->r->val;
    return ans;
}
int query(int cnt, int st, int dr, nodS* p)
{
    if(p->val<cnt)
        return dr+1;

    if(st==dr)
        return st;

    int mij=(st+dr)/2;
    if(p->l->val>=cnt)
        return query(cnt, st, mij, p->l);

    cnt-=p->l->val;
    return query(cnt, mij+1, dr, p->r);
}
void repr(int st, int dr, nodS *p)
{
    cout<<st<<' '<<dr<<' '<<p->val<<'\n';

    if(st!=dr)
    {
        int mij=(st+dr)/2;
        repr(st, mij, p->l);
        repr(mij+1, dr, p->r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    v[n+1]=build(1, n);

    for(i=n;i>=1;i--)
    {
        v[i]=updpers(i, 1, n, v[i+1]);

        p=last[a[i]];
        if(p)
            v[i]=updpers(p, 1, n, v[i]);

        last[a[i]]=i;
    }

    /*
    for(i=n;i>=1;i--)
    {
        cout<<i<<'\n'<<'\n';
        repr(1, n, v[i]);
        cout<<'\n';
    }
    return 0;
    */

    for(k=1;k<=n;k++)
    {
        p=1;
        ans=0;
        while(p<=n)
        {
            p=query(k+1, 1, n, v[p]);
            ans++;
        }

        cout<<ans<<' ';
    }
    return 0;
}
