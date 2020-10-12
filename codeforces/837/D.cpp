#include <iostream>
#define f first
#define s second

using namespace std;
int n,k,i,j,a,b,nrk,nr2,ans;
long long x;
pair<int, int> v[205];
int dp[2][205][6005];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a=b=0;
        while(x%2==0)
        {
            a++;
            x/=2;
        }
        while(x%5==0)
        {
            b++;
            x/=5;
        }
        v[i]={a, b};
    }

    /*
    for(i=1;i<=n;i++)
    {
        cout<<v[i].f<<' '<<v[i].s<<'\n';
    }
    */

    for(nrk=0;nrk<=k;nrk++)
        for(nr2=0;nr2<=6000;nr2++)
            dp[1][nrk][nr2]=-1e6;
    dp[1][0][0]=0;

    for(i=1;i<=n;i++)
    {
        for(nrk=0;nrk<=k;nrk++)
            for(nr2=0;nr2<=6000;nr2++)
                dp[0][nrk][nr2]=dp[1][nrk][nr2];

        for(nrk=0;nrk<=k;nrk++)
            for(nr2=0;nr2<=6000;nr2++)
            {
                dp[1][nrk][nr2]=dp[0][nrk][nr2];
                if(nr2-v[i].s>=0 && nrk)
                    dp[1][nrk][nr2]=max(dp[1][nrk][nr2], dp[0][nrk-1][nr2-v[i].s]+v[i].f);
            }
    }

    ans=0;
    for(nr2=0;nr2<=6000;nr2++)
        ans=max(ans, min(nr2, dp[1][k][nr2]));
    cout<<ans;
    return 0;
}
