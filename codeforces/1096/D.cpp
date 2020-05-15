#include <iostream>

using namespace std;
int n,i;
char s[100005];
long long a[100005];
long long dp[100005][5];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>s[i];

    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {

        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][1];
        dp[i][2]=dp[i-1][2];
        dp[i][3]=dp[i-1][3];

        if(s[i]=='h')
        {
            dp[i][0]+=a[i];
        }

        if(s[i]=='a')
        {
            dp[i][1]+=a[i];
            dp[i][1]=min(dp[i][1], dp[i-1][0]);
        }

        if(s[i]=='r')
        {
            dp[i][2]+=a[i];
            dp[i][2]=min(dp[i][2], dp[i-1][1]);
            dp[i][2]=min(dp[i][2], dp[i-1][0]);
        }

        if(s[i]=='d')
        {
            dp[i][3]+=a[i];
            dp[i][3]=min(dp[i][3], dp[i-1][2]);
            dp[i][3]=min(dp[i][3], dp[i-1][1]);
            dp[i][3]=min(dp[i][3], dp[i-1][0]);
        }
    }

    /*
    for(i=1;i<=n;i++)
    {
        cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<'\n';
    }
    */

    cout<<dp[n][3];
    return 0;
}
