#include <iostream>

using namespace std;

long long t,n,p,k,x,y,ans,i;
char ch;
int a[100005];
long long dp[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>p>>k;
        for(i=1;i<=n;i++)
        {
            cin>>ch;
            a[i]=ch-'0';
        }
        cin>>x>>y;

        for(i=n;i>=1;i--)
        {
            if(i+k<=n)
                dp[i]=dp[i+k];
            else
                dp[i]=0;

            dp[i]+=1-a[i];
        }

        ans=1e18;
        for(i=p;i<=n;i++)
            ans=min(ans, (i-p)*y+dp[i]*x);
        cout<<ans<<'\n';
    }
    return 0;
}
