#include <bits/stdc++.h>

using namespace std;
int n,k,i,x,ans,last;
bool ok;
int a[500005];
bool fix[500005];

int calc(int l, int r, int mini, int maxi)
{
    //cout<<l<<' '<<r<<' '<<mini<<' '<<maxi<<'\n';
    if(maxi<mini)
    {
        ok=false;
        return 0;
    }
    if(l>r)
        return 0;

    vector<int> v;
    v.push_back(mini);

    for(int i=l;i<=r;i++)
    {
        if(a[i]<mini || a[i]>maxi)
        {
            continue;
        }

        int p=upper_bound(v.begin(), v.end(), a[i])-v.begin();
        if(p==v.size())
            v.push_back(a[i]);
        else
            v[p]=a[i];
    }

    return (r-l+1)-v.size()+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]-=i;
    }

    for(i=1;i<=k;i++)
    {
        cin>>x;
        fix[x]=true;
    }

    ans=0;
    last=0;
    ok=true;
    a[0]=-2e9;
    for(i=1;i<=n;i++)
    {
        if(!fix[i])
            continue;

        ans+=calc(last+1, i-1, a[last], a[i]);
        last=i;
    }
    ans+=calc(last+1, n, a[last], 2e9);

    if(!ok)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
