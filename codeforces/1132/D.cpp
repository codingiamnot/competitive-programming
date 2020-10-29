#include <bits/stdc++.h>

using namespace std;

long long n,k,i;
long long st,dr,mij,last;
long long a[200005];
long long c[200005];
vector<pair<long long, long long>> v[200005];

bool ok(long long x)
{
    for(int i=0;i<=k;i++)
        v[i].clear();

    for(int i=1;i<=n;i++)
    {
        if(a[i]/c[i]+1<=k)
            v[a[i]/c[i]+1].push_back({a[i], c[i]});
    }

    int p=0;
    for(long long i=0;i<k;i++)
    {
        /*
        for(int j=0;j<=k;j++)
        {
            if(v[j].empty())
                continue;

            cout<<j<<'\n';
            for(auto it : v[j])
                cout<<it.first<<' '<<it.second<<'\n';
        }
        cout<<'\n';
        */

        while(p<=k && v[p].empty())
            p++;

        if(p>=k)
            return true;

        long long a=v[p].back().first;
        long long c=v[p].back().second;
        v[p].pop_back();

        if(a-c*i<0)
            return false;

        a+=x;
        if(a/c+1 <= k)
            v[a/c+1].push_back({a, c});
    }

    while(p<=k && v[p].empty())
        p++;
    if(p>=k)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;

    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>c[i];

    last=1e18;
    st=0;
    dr=2e12;

    while(st<=dr)
    {
        mij=(st+dr)/2;

        if(ok(mij))
        {
            last=mij;
            dr=mij-1;
        }
        else
            st=mij+1;
    }

    if(last==1e18)
        cout<<-1;
    else
        cout<<last;
    return 0;
}
