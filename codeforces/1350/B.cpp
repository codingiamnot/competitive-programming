#include <iostream>

using namespace std;
int t,n,i,ans,j;
int a[100005];
int dp[100005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=n;i>=1;i--)
        {
            dp[i]=1;
            for(j=2*i;j<=n;j+=i)
                if(a[j]>a[i])
                    dp[i]=max(dp[i], dp[j]+1);
        }

        ans=0;
        for(i=1;i<=n;i++)
            ans=max(ans, dp[i]);

        cout<<ans<<'\n';
    }
    return 0;
}
