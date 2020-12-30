#include <bits/stdc++.h>

using namespace std;

int t,n,i,x,ans,r;
int fr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;

        for(i=1;i<=2*n+1;i++)
            fr[i]=0;

        for(i=1;i<=n;i++)
        {
            cin>>x;
            fr[x]++;
        }

        ans=0;
        r=0;
        for(i=1;i<=2*n+1;i++)
        {
            if(fr[i] || r)
                ans++;

            if(fr[i]>=2 || (fr[i]==1 && r))
                r=1;
            else
                r=0;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
