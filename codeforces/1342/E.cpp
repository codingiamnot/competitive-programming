#include <iostream>
#define mod 998244353

using namespace std;
long long n,k,ans,c,nans;
long long fact[200005];
long long put(long long baza, long long exp)
{
    if(exp==0)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
        return (ans*baza)%mod;
    return ans;
}
long long comb(long long k, long long n)
{
    long long b=fact[k];
    long long a=fact[n]*put(fact[n-k], mod-2);
    a%=mod;

    return (a*put(b, mod-2))%mod;
}
void genfact(long long n)
{
    fact[0]=1;
    for(long long i=1;i<=n;i++)
        fact[i]=(fact[i-1]*i)%mod;
}
int main()
{
    cin>>n>>k;
    c=n-k;

    if(c<0)
    {
        cout<<0;
        return 0;
    }
    genfact(n);

    for(long long i=0;i<=c;i++)
    {
        nans=comb(i, c)*put(c-i, n);
        nans%=mod;

        if(i%2)
        {
            ans-=nans;
            while(ans<0)
                ans+=mod;
        }
        else
        {
            ans+=nans;
            ans%=mod;
        }
    }

    ans*=comb(c, n);
    ans%=mod;
    if(k)
    {
        ans*=2;
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
