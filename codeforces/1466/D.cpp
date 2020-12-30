#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    long long deg, w;
};

int t,n,i,x,y;
long long ans;
nodS nod[200005];
vector<pair<long long, long long>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=0;
        v.clear();

        for(i=1;i<=n;i++)
        {
            cin>>nod[i].w;
            nod[i].deg=0;
        }

        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            nod[x].deg++;
            nod[y].deg++;
        }

        for(i=1;i<=n;i++)
        {
            ans+=nod[i].w;

            if(nod[i].deg>1)
                v.push_back({nod[i].w, nod[i].deg-1});
        }

        sort(v.begin(), v.end());

        cout<<ans<<' ';
        for(i=2;i<n;i++)
        {
            ans+=v.back().first;
            v.back().second--;

            if(!v.back().second)
                v.pop_back();

            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
