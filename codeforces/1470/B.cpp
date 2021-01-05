#include <bits/stdc++.h>

using namespace std;

long long t,n,q,i,j,x,d,nr;
long long ans0,ans1;
map<vector<long long>, long long> m;

int ciur[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(i=2;i<=1e6;i++)
    {
        if(!ciur[i])
        {
            ciur[i]=i;
            for(j=2*i;j<=1e6;j+=i)
                if(!ciur[j] || ciur[j]>i)
                    ciur[j]=i;
        }
    }

    cin>>t;
    while(t)
    {
        t--;
        m.clear();
        ans0=0;
        ans1=0;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            vector<long long> v;

            while(x!=1)
            {
                d=ciur[x];
                nr=0;

                while(x%d==0)
                {
                    nr++;
                    x/=d;
                }

                if(nr%2)
                    v.push_back(d);
            }

            sort(v.begin(), v.end());

            m[v]++;
        }

        /*
        for(auto &it :m)
        {
            for(int it2 : it.first)
                cout<<it2<<' ';
            cout<<'\n';
            cout<<"cnt "<<it.second<<'\n';
        }
        */

        for(auto &it : m)
        {
            ans0=max(ans0, it.second);

            if(it.second%2==0 || it.first.empty())
                ans1+=it.second;
        }

        cin>>q;
        while(q)
        {
            q--;
            cin>>x;
            if(!x)
                cout<<ans0<<'\n';
            else
                cout<<max(ans0, ans1)<<'\n';
        }
    }
    return 0;
}
