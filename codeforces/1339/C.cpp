#include <bits/stdc++.h>

using namespace std;
int t,n,k,i,b,ans,maxi;
bool ok;
int dif,a[100005];
int maxb(long long nr)
{
    for(int b=31;b>=0;b--)
        if(nr>>b)
            return b;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ans=0;
        cin>>n;

        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=2;i<=n;i++)
        {
            if(a[i]>=a[i-1])
                continue;

            else
            {
                dif=a[i-1]-a[i];
                a[i]=a[i-1];
                ans=max(ans, maxb(dif)+1);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
