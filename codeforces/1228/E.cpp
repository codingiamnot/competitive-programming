#include <iostream>
#define mod 1000000007

using namespace std;
long long put(long long baza, long long exp)
{
    if(!exp)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
    {
        ans*=baza;
        ans%=mod;
    }

    return ans;
}
long long n,k,i,nr,col,nans;
long long dp[305][305];
long long fact[305];
long long inv[305];

void genfact()
{
    fact[0]=1;
    inv[0]=1;
    for(long long i=1;i<=n;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=put(fact[i], mod-2);
    }
}
long long comb(long long k, long long n)
{
    long long ans=fact[n]*inv[n-k];
    ans%=mod;
    ans*=inv[k];
    ans%=mod;
    return ans;
}
int main()
{
    cin>>n>>k;
    genfact();
    dp[1][n]=1;
    for(i=1;i<=n;i++)
    {
        for(col=0;col<=n;col++)
        {
            for(nr=0;nr<=col;nr++)
            {
                nans=comb(nr, col);
                nans*=put(k-1, col-nr);
                nans%=mod;
                nans*=put(k, n-col);
                nans%=mod;

                if(!nr)
                {
                    nans-=put(k-1, n);
                    if(nans<0)
                        nans+=mod;
                }
                nans*=dp[i][col];
                nans%=mod;

                dp[i+1][col-nr]+=nans;
                dp[i+1][col-nr]%=mod;
            }
        }
    }

    cout<<dp[n+1][0];
    return 0;
}
