#include <bits/stdc++.h>

using namespace std;
long long i,t,n,x,ans,nr;
bool ok;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ok=false;
        ans=0;
        nr=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x==1)
            {
                ans+=nr;
                ok=true;
                nr=0;
            }
            else if(ok)
                nr++;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
