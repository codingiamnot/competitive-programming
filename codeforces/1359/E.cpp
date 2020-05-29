#include <iostream>
#define mod 998244353

using namespace std;
long long n,k,ans,nr,i;
long long cnt(long long l, long long r, long long m)
{
    long long ans=0;
    r+=m-r%m-1;
    return (r-l+1)/m;
}
long long put(long long baza, long long exp)
{
    if(exp==0)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
        return (ans*baza)%mod;
    else
        return ans;
}
long long comb(long long k, long long n)
{
    long long a=1, b=1;

    for(long long i=n-k+1;i<=n;i++)
    {
        a*=i;
        a%=mod;
    }

    for(long long i=1;i<=k;i++)
    {
        b*=i;
        b%=mod;
    }

    return (a*put(b, mod-2))%mod;

}
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        nr=cnt(2*i, n, i);
        if(nr<k-1)
            break;
        ans+=comb(k-1, nr);
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
