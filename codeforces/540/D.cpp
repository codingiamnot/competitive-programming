#include <iostream>

using namespace std;
int r,p,s,i,j,k;
double ans,total;
double dp[105][105][105];
int main()
{
    cin>>r>>s>>p;
    dp[r][s][p]=1;

    for(i=r;i>=0;i--)
        for(j=s;j>=0;j--)
            for(k=p;k>=0;k--)
            {
                if(!i && !j)
                    continue;
                if(!i && !k)
                    continue;
                if(!j && !k)
                    continue;

                total=i*j+i*k+j*k;

                if(i)
                    dp[i-1][j][k]+=dp[i][j][k]*i*k/total;
                if(j)
                    dp[i][j-1][k]+=dp[i][j][k]*i*j/total;
                if(k)
                    dp[i][j][k-1]+=dp[i][j][k]*j*k/total;
            }

    cout.precision(12);

    for(i=1;i<=r;i++)
        ans+=dp[i][0][0];
    cout<<ans<<' ';

    ans=0;
    for(j=1;j<=s;j++)
        ans+=dp[0][j][0];
    cout<<ans<<' ';

    ans=0;
    for(k=1;k<=p;k++)
        ans+=dp[0][0][k];
    cout<<ans;
    return 0;
}
