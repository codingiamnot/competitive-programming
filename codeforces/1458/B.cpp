#include <iostream>

using namespace std;

int n,i,nr,lib,sum;
double ans;
int a[105],b[105];
int dp[105][105][10005];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        sum+=b[i];
    }


    for(i=0;i<=n;i++)
        for(nr=0;nr<=n;nr++)
            for(lib=0;lib<=100*n;lib++)
                dp[i][nr][lib]=-1e9;

    dp[0][0][0]=0;

    for(i=1;i<=n;i++)
        for(nr=0;nr<=n;nr++)
            for(lib=0;lib<=100*n;lib++)
            {
                dp[i][nr][lib]=dp[i-1][nr][lib];

                if(nr && lib>=a[i])
                    dp[i][nr][lib]=max(dp[i][nr][lib], dp[i-1][nr-1][lib-a[i]]+b[i]);
            }

    cout.precision(12);
    for(nr=1;nr<=n;nr++)
    {
        ans=-1e9;
        for(lib=0;lib<=100*n;lib++)
        {
            ans=max(ans, min((double)lib, (double)dp[n][nr][lib]/2 + (double)sum/2));
        }

        cout<<ans<<' ';
    }
    return 0;
}
