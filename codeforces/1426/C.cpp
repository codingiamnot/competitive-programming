#include <bits/stdc++.h>

using namespace std;
long long t,n,ans,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=1e18;
        for(x=0;x<=70000;x++)
            ans=min(ans, x-1+(n+x)/(x+1));

        cout<<ans<<'\n';
    }
    return 0;
}
