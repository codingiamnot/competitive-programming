#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update> oset;

struct pos
{
    int x,r,f;

    bool operator<(pos b) const
    {
        return r<b.r;
    }
};

int query(oset &s, int st, int dr)
{
    return s.order_of_key({dr, 1e9}) - s.order_of_key({st-1, 1e9});
}

int n,k,i,j;
long long ans;
oset m[10005];
pos v[100005];

int main()
{
    cin>>n>>k;

    for(i=1;i<=n;i++)
        cin>>v[i].x>>v[i].r>>v[i].f;

    sort(v+1, v+n+1);


    for(i=1;i<=n;i++)
        m[v[i].f].insert({v[i].x, i});

    for(i=1;i<=n;i++)
    {
        m[v[i].f].erase({v[i].x, i});

        for(j=max(0, v[i].f-k);j<=min((int)1e4, v[i].f+k);j++)
            ans+=query(m[j], v[i].x-v[i].r, v[i].x+v[i].r);
    }

    cout<<ans;
    return 0;
}
