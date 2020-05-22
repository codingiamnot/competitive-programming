#include <bits/stdc++.h>

using namespace std;
long long n,i,k,nr,j;
long long a[2005];
long long dp[2005][2005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            for(j=1;j<=n;j++)
                if(a[j]!=1)
                    nr++;
            cout<<nr;
            return 0;
        }
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i+k-1<=n;i++)
        {
           if(k==1)
                dp[i][i+k-1]=a[i];
            else
                dp[i][i+k-1]=__gcd(a[i], dp[i+1][i+k-1]);

            if(dp[i][i+k-1]==1)
            {
                cout<<k+n-2;
                return 0;
            }
        }
    }

    cout<<-1;
    return 0;
}
