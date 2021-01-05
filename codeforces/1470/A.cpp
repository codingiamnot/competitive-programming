#include <bits/stdc++.h>

using namespace std;

int t,n,m,i,cnt;
long long ans;
long long a[300005];
long long c[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=m;i++)
            cin>>c[i];
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);

        ans=0;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            if(cnt+1>a[i])
                ans+=c[a[i]];
            else
            {
                cnt++;
                ans+=c[cnt];
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
