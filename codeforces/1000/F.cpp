#include <bits/stdc++.h>

using namespace std;

int n,i,q,l,r;
int a[500005];
int last[500005];
int ansv[500005];

vector<pair<int, int>> qv[500005];
vector<pair<int, int>> seg;

void upd(int i, int st, int dr, int p, int val)
{
    if(st==dr)
    {
        seg[p]={val, st};
        return;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
        upd(i, st, mij, 2*p, val);
    else
        upd(i, mij+1, dr, 2*p+1, val);

    seg[p]=min(seg[2*p], seg[2*p+1]);
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

    return min(query(stt, mij, st, mij, 2*p), query(mij+1, drt, mij+1, dr, 2*p+1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    seg.resize(4*n+4);

    for(i=1;i<=n;i++)
        cin>>a[i];

    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>l>>r;
        qv[r].push_back({i, l});
    }

    for(i=1;i<=n;i++)
        upd(i, 1, n, 1, n+1);

    for(i=1;i<=n;i++)
    {
        int id=last[a[i]];
        last[a[i]]=i;

        if(id)
            upd(id, 1, n, 1, n+1);

        upd(i, 1, n, 1, id+1);

        for(auto it : qv[i])
        {
            auto ans=query(it.second, i, 1, n, 1);

            if(ans.first<=it.second)
                ansv[it.first]=a[ans.second];
        }
    }

    for(i=1;i<=q;i++)
        cout<<ansv[i]<<'\n';
    return 0;
}
