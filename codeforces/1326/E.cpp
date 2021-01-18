#include <bits/stdc++.h>

using namespace std;

struct segS
{
    int pre, suf;
};

int n,i,x,p;
vector<int> v[300005];
vector<segS> seg;

void upd(int i, int st, int dr, int p, int val)
{
    if(st==dr)
    {
        if(val==1)
            seg[p].suf++;
        else
            seg[p].pre++;

        if(seg[p].suf && seg[p].pre)
            seg[p].pre=seg[p].suf=0;

        return;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
        upd(i, st, mij, 2*p, val);
    else
        upd(i, mij+1, dr, 2*p+1, val);

    seg[p].pre=seg[2*p].pre + max(0, seg[2*p+1].pre-seg[2*p].suf);
    seg[p].suf=max(0, seg[2*p].suf-seg[2*p+1].pre) + seg[2*p+1].suf;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    seg.resize(4*n+4);

    for(i=1;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
    }

    p=n;
    for(int it : v[p])
        upd(it, 1, n, 1, 1);

    for(i=1;i<=n;i++)
    {
        cout<<p<<' ';

        cin>>x;
        upd(x, 1, n, 1, -1);

        while(!seg[1].suf && p>1)
        {
            p--;
            for(int it : v[p])
                upd(it, 1, n, 1, 1);
        }
    }
    return 0;
}
