#include <iostream>

using namespace std;
int n,i,j,k;
int a[505];
int dp[505][505];
int dp2[505];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
        dp[i][i]=a[i];

    for(k=1;k<n;k++)
        for(i=1;i+k<=n;i++)
            for(j=i;j<i+k;j++)
                if(dp[i][j]==dp[j+1][i+k] && dp[i][j])
                    dp[i][i+k]=dp[i][j]+1;



    for(i=1;i<=n;i++)
        dp2[i]=n+1;

    dp2[0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(dp[i][j])
            {
                dp2[j]=min(dp2[j], dp2[i-1]+1);
            }
        }
    }
    cout<<dp2[n];
    return 0;
}
