#include <bits/stdc++.h>

using namespace std;
long long t,n,i,maxi,ans;
long long a[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        maxi=0;
        ans=-1;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            maxi=max(maxi, a[i]);
        }
        a[0]=1e18;
        a[n+1]=1e18;
        for(i=1;i<=n;i++)
        {
            if(a[i]==maxi && (a[i]>a[i-1] || a[i]>a[i+1]))
            {
                ans=i;
                break;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
