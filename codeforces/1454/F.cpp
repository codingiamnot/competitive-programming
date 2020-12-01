#include <bits/stdc++.h>

using namespace std;

int n,i;
int a[200005];
int maxl[200005];
int maxr[200005];
void solve()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];

    for(int i=1; i<=n; i++)
        maxl[i]=max(maxl[i-1], a[i]);

    maxr[n+1]=0;
    for(int i=n; i>=1; i--)
        maxr[i]=max(maxr[i+1], a[i]);

    vector<int> v;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==maxl[n])
            v.push_back(i);
    }

    if(v.size()>=3)
    {
        cout<<"YES\n";
        cout<<v[1]-1<<' '<<1<<' '<<n-v[1]<<'\n';
        return;
    }

    int l=v[0];
    int r=v.back();

    int val=1e9;
    for(int i=l;i<=r;i++)
        val=min(val, a[i]);

    while(l>1 && r<n)
    {
        if(val==maxl[l-1] && val==maxr[r+1])
        {
            cout<<"YES\n";
            cout<<l-1<<' '<<r-l+1<<' '<<n-r<<'\n';
            return;
        }

        int vall=min(min(val, a[l-1]), min(maxl[l-2], maxr[r+1]));
        int valr=min(min(val, a[r+1]), min(maxl[l-1], maxr[r+2]));

        if(vall>valr)
        {
            l--;
            val=min(val, a[l]);
        }
        else
        {
            r++;
            val=min(val, a[r]);
        }

    }

    cout<<"NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;
    while(t)
    {
        t--;
        solve();
    }
    return 0;
}
