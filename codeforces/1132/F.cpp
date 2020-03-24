#include <iostream>

using namespace std;
string s;
int n,i,k,j,lp;
int dp[505][505];
int main()
{
    cin>>n;
    s.resize(n+1);
    for(i=1;i<=n;i++)
        cin>>s[i];

    for(k=0;k<n;k++)
    {
        for(i=1;i+k<=n;i++)
        {
            dp[i][i+k]=1+dp[i+1][i+k];

            for(j=i+1;j<=i+k;j++)
            {
                if(s[i]==s[j])
                {
                    if(j==i+1)
                        dp[i][i+k]=min(dp[i][i+k], dp[i+1][i+k]);
                    else
                        dp[i][i+k]=min(dp[i][i+k], dp[i+1][j-1]+dp[j][i+k]);
                }
            }
        }
    }

    cout<<dp[1][n];
    return 0;
}
