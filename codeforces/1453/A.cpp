#include <bits/stdc++.h>

using namespace std;

int t,i,n,m,ans,x;
int fr[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        memset(fr, 0, sizeof fr);
        ans=0;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            fr[x]=1;
        }
        for(i=1;i<=m;i++)
        {
            cin>>x;
            if(fr[x])
                ans++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
