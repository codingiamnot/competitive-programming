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

struct seg
{
    int l, r;
    bool operator<(seg b) const
    {
        return l<b.l;
    }
};

int t,n,i,ans,nans;
seg v[200005];
oset st, dr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        st.clear();
        dr.clear();
        t--;
        ans=1e9;

        cin>>n;

        for(i=1;i<=n;i++)
            cin>>v[i].l>>v[i].r;

        sort(v+1, v+n+1);

        for(i=1;i<=n;i++)
            dr.insert({v[i].l, i});

        for(i=1;i<=n;i++)
        {
            dr.erase({v[i].l, i});

            nans=0;
            nans+=st.order_of_key({v[i].l, 0});
            nans+=dr.size()-dr.order_of_key({v[i].r, n+1});

            //cout<<i<<' '<<nans<<'\n';

            ans=min(ans, nans);

            st.insert({v[i].r, i});
        }

        cout<<ans<<'\n';
    }
    return 0;
}
