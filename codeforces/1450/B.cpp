#include <bits/stdc++.h>

using namespace std;

struct pct
{
    int x, y;
};
int t,n,k;
pct a[105];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y;

    for(int i=1;i<=n;i++)
    {
        bool ok=true;

        for(int j=1;j<=n;j++)
        {
            if(abs(a[i].x-a[j].x) + abs(a[i].y-a[j].y) > k)
                ok=false;
        }

        if(ok)
        {
            cout<<"1\n";
            return;
        }
    }

    cout<<"-1\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        solve();
    }
    return 0;
}
