#include <iostream>

using namespace std;
int n,i,j,k,q,x,y;
int val[5005][5005];
int dp[5005][5005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>val[1][i];

    for(i=2;i<=n;i++)
    {
        for(j=1;j<=n-i+1;j++)
        {
            val[i][j]=val[i-1][j]^val[i-1][j+1];
        }
    }

    for(k=0;k<n;k++)
    {
        for(i=1;i+k<=n;i++)
        {
            dp[i][i+k]=val[k+1][i];
            dp[i][i+k]=max(dp[i][i+k], dp[i+1][i+k]);
            dp[i][i+k]=max(dp[i][i+k], dp[i][i+k-1]);
        }
    }

    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        cout<<dp[x][y]<<'\n';
    }
    return 0;
}
