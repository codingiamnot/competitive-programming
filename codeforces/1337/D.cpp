#include <bits/stdc++.h>

using namespace std;
int t,rn,gn,an,i;
vector <long long> r,g,a;
long long ans;
long long calc(long long a, long long b, long long c)
{
    return (a-b)*(a-b) + (b-c)*(b-c) + (c-a)*(c-a);
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ans=3*1e18;
        cin>>rn>>gn>>an;
        r.resize(rn);
        g.resize(gn);
        a.resize(an);

        for(i=0;i<rn;i++)
            cin>>r[i];
        sort(r.begin(), r.end());

        for(i=0;i<gn;i++)
            cin>>g[i];
        sort(g.begin(), g.end());

        for(i=0;i<an;i++)
            cin>>a[i];
        sort(a.begin(), a.end());

        for(int it : r)
        {
            auto pozl=upper_bound(g.begin(), g.end(), it);
            auto pozr=lower_bound(a.begin(), a.end(), it);

            if(pozl!=g.begin() && pozr!=a.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));

            pozl=upper_bound(a.begin(), a.end(), it);
            pozr=lower_bound(g.begin(), g.end(), it);

            if(pozl!=a.begin() && pozr!=g.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));
        }

        for(int it : g)
        {
            auto pozl=upper_bound(r.begin(), r.end(), it);
            auto pozr=lower_bound(a.begin(), a.end(), it);

            if(pozl!=r.begin() && pozr!=a.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));

            pozl=upper_bound(a.begin(), a.end(), it);
            pozr=lower_bound(r.begin(), r.end(), it);

            if(pozl!=a.begin() && pozr!=r.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));
        }

        for(int it : a)
        {
            auto pozl=upper_bound(g.begin(), g.end(), it);
            auto pozr=lower_bound(r.begin(), r.end(), it);

            if(pozl!=g.begin() && pozr!=r.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));

            pozl=upper_bound(r.begin(), r.end(), it);
            pozr=lower_bound(g.begin(), g.end(), it);

            if(pozl!=r.begin() && pozr!=g.end())
                ans=min(ans, calc(it, *(--pozl), *pozr));
        }

        cout<<ans<<'\n';
    }
    return 0;
}
