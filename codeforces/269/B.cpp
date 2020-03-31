#include <iostream>

using namespace std;
int n,m,i,j;
int v[5005];
int dp[5005];
int ans;
double x;
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v[i]>>x;


    for(i=1;i<=n;i++)
    {
        dp[i]=1;
        for(j=1;j<i;j++)
        {
            if(v[j]<=v[i])
                dp[i]=max(dp[i], dp[j]+1);
        }
    }

    for(i=1;i<=n;i++)
        ans=max(ans, dp[i]);

    cout<<n-ans;
    return 0;
}
