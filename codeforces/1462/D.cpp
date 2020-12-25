#include <bits/stdc++.h>

using namespace std;

int t,n,i,j,sum,sumt,last,ans,nans;
bool ok;
int a[3005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;

        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sumt=0;
        ans=1e9;
        for(i=1;i<=n;i++)
        {
            sumt+=a[i];
            sum=0;
            nans=i-1;
            last=i;
            ok=true;

            for(j=i+1;j<=n;j++)
            {
                sum+=a[j];
                if(sum>sumt)
                {
                    ok=false;
                    break;
                }
                if(sum==sumt)
                {
                    nans+=j-last-1;
                    last=j;
                    sum=0;
                }
            }

            if(sum)
                ok=false;

            if(ok)
                ans=min(ans, nans);
        }

        if(ans==1e9)
            cout<<"-1\n";
        else
            cout<<ans<<'\n';
    }
    return 0;
}
