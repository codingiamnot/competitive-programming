#include <bits/stdc++.h>
#define mod 998244353

using namespace std;

long long n,i,sp,si,inv2;
long long dp[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    inv2=499122177;

    sp=1;
    si=0;

    for(i=1;i<=n;i++)
    {
        sp*=inv2;
        sp%=mod;

        si*=inv2;
        si%=mod;

        if(i%2)
        {
            dp[i]=sp;
            si+=dp[i];
            si%=mod;
        }
        else
        {
            dp[i]=si;
            sp+=dp[i];
            sp%=mod;
        }
    }

    cout<<dp[n];
    return 0;
}
