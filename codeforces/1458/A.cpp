#include <bits/stdc++.h>

using namespace std;

long long n,m,i,x,ans;
long long a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=2;i<=n;i++)
        ans=__gcd(ans, a[i]-a[1]);

    for(i=1;i<=m;i++)
    {
        cin>>x;
        cout<<abs(__gcd(a[1]+x, ans))<<' ';
    }
    return 0;
}
