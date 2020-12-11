#include <bits/stdc++.h>

using namespace std;

long long n,i,j,nt;
long long t[5005],x[5005];
long long mtimp[5005];
bool dp[5005][5005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>t[i]>>x[i];

    for(i=1;i<=n;i++)
        mtimp[i]=(1e9)+1;

    for(i=0;i<n;i++)
    {
        if(mtimp[i]<=t[i])
        {
            mtimp[i+1]=min(mtimp[i+1], max(mtimp[i]+abs(x[i+1]-x[i]), t[i]));

            for(j=i+2;j<=n;j++)
            {
                nt=max(mtimp[i]+abs(x[j]-x[i]), t[i])+abs(x[j]-x[i+1]);
                if(nt<=t[i+1])
                    dp[i+1][j]=true;
            }
        }

        if(t[i+1]-t[i]>=abs(x[i+1]-x[i]))
        {
            for(j=i+2;j<=n;j++)
                if(dp[i][j])
                    dp[i+1][j]=true;
        }

        if(dp[i][i+1])
        {
            mtimp[i+2]=min(mtimp[i+2], max(t[i]+abs(x[i+2]-x[i]), t[i+1]));

            for(j=i+3;j<=n;j++)
            {
                nt=max(t[i]+abs(x[j]-x[i]), t[i+1])+abs(x[j]-x[i+2]);
                if(nt<=t[i+2])
                    dp[i+2][j]=true;
            }
        }
    }

    /*
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    */

    if(mtimp[n]<=t[n] || dp[n-1][n])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
