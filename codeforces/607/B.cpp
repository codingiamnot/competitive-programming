#include <iostream>

using namespace std;
int n,i,k,j;
int v[505];
int dp[505][505];
bool pal(int st, int dr)
{
    int i=st;
    int j=dr;
    while(i<=dr)
    {
        if(v[i]!=v[j])
            return false;

        i++;
        j--;
    }

    return true;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];


    for(k=0;k<n;k++)
    {
        for(i=1;i+k<=n;i++)
        {
            if(pal(i, i+k))
            {
                dp[i][i+k]=1;
                continue;
            }
            dp[i][i+k]=1+dp[i+1][i+k];

            for(j=i+1;j<=i+k;j++)
            {
                if(v[i]!=v[j])
                    continue;

                if(j==i+1)
                {
                    dp[i][i+k]=min(dp[i][i+k], 1+dp[i+2][i+k]);
                    continue;
                }

                if(j==i+k)
                {
                    dp[i][i+k]=min(dp[i][i+k], dp[i+1][i+k-1]);
                    continue;
                }


                dp[i][i+k]=min(dp[i][i+k], dp[i+1][j-1]+dp[j+1][i+k]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
