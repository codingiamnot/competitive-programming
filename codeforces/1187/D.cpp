#include <bits/stdc++.h>

using namespace std;

int n,i,t;
bool ok;
int a[300005];
int b[300005];
vector<int> seg;
vector<int> s[300005];

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
    if(stt==st && drt==dr)
        return seg[p];

    int mij=(st+dr)/2;

    if(drt<=mij)
        return query(stt, drt, st, mij, 2*p);
    if(stt>mij)
        return query(stt, drt, mij+1, dr, 2*p+1);

    return min(query(stt, mij, st, mij, 2*p), query(mij+1, drt, mij+1, dr, 2*p+1));
}
void add(int p, int val)
{
    s[p].push_back(val);
    upd(p, val, 1, n, 1);
}
void del(int p)
{
    if(s[p].empty())
    {
        ok=false;
        return;
    }
    
    s[p].pop_back();
    
    if(s[p].empty())
    {
        ok=false;
        return;
    }
    upd(p, s[p].back(), 1, n, 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            s[i].clear();

        seg.resize(4*n+4);
        fill(seg.begin(), seg.end(), n+1);

        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            cin>>b[i];

        for(i=1;i<=n;i++)
            add(i, n+1);

        for(i=n;i>=1;i--)
            add(a[i], i);

        ok=true;
        for(i=1;i<=n;i++)
        {
            if(query(1, b[i], 1, n, 1) != s[b[i]].back())
                ok=false;

            del(b[i]);
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
