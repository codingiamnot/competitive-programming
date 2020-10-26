#include <bits/stdc++.h>

using namespace std;
int n,i,j,l,r;
vector<int> v[100005];
int a[100005];
vector<pair<int, int>> qv[100005];
vector<int> seg;
int ans[100005];
void upd(int i, int val, int st, int dr, int p)
{
    if(st==dr)
    {
        seg[p]=val;
        return;
    }

    int mij=(st+dr)/2;

    if(i<=mij)
        upd(i, val, st, mij, 2*p);
    else
        upd(i, val, mij+1, dr, 2*p+1);

    seg[p]=min(seg[2*p], seg[2*p+1]);
}
int query(int stt, int drt, int st, int dr, int p)
{
    if(stt>drt)
        return n+1;

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
    for(i=1;i<=n+1;i++)
        v[i].push_back(0);
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    for(i=1;i<=n+1;i++)
        v[i].push_back(n+1);

    for(i=1;i<=n+1;i++)
    {
        for(j=1;j<v[i].size();j++)
        {
            l=v[i][j-1]+1;
            r=v[i][j]-1;

            if(r>=l)
                qv[r].push_back({l, i});
        }
    }

    for(i=1;i<=n;i++)
        upd(i, -1, 1, n, 1);

    for(i=1;i<=n;i++)
    {
        upd(a[i], i, 1, n, 1);

        for(auto it : qv[i])
        {
            ans[it.second]|=(query(1, it.second-1, 1, n, 1)>=it.first);
        }
    }

    for(i=1;i<=n+1;i++)
    {
        if(!ans[i])
        {
            cout<<i;
            return 0;
        }
    }

    cout<<n+2;
    return 0;
}
