#include <bits/stdc++.h>

using namespace std;
int n,i,j,x,maxi;
int fr[2000006];
int dp[2000006];
int ans;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        fr[x]=1;
        maxi=max(maxi, x);
    }


    for(i=1;i<=2*maxi;i++)
    {
        if(fr[i-1])
            dp[i]=i-1;
        else
            dp[i]=dp[i-1];
    }

    for(i=1;i<=maxi;i++)
    {
        if(!fr[i])
            continue;

        for(j=2*i;j<=2*maxi;j+=i)
            ans=max(ans, dp[j]%i);
    }
    cout<<ans;
    return 0;
}
