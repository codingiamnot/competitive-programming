#include <bits/stdc++.h>

using namespace std;
long long t,p,q,ans,d,nr,nans;
vector<pair<long long, long long>> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>p>>q;

        if(p%q)
        {
            cout<<p<<'\n';
            continue;
        }

        ans=0;
        v.clear();
        d=2;
        while(d*d<=q)
        {
            if(q%d==0)
            {
                nr=0;
                while(q%d==0)
                {
                    q/=d;
                    nr++;
                }
                v.push_back({d, nr});
            }
            d++;
        }

        if(q>1)
            v.push_back({q, 1});

        for(auto it : v)
        {
            d=it.first;
            nr=it.second;
            nans=p;

            while(nans%d==0)
                nans/=d;

            while(nr>1)
            {
                nans*=d;
                nr--;
            }

            ans=max(ans, nans);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
