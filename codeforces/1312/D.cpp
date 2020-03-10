#include <iostream>
#define mod 998244353

using namespace std;
long long n,m,ans;
long long put(long long baza, long long exponent)
{
    if(exponent==0)
        return 1;

    if(exponent==1)
        return baza;

    long long ans = put(baza, exponent/2);

    if(exponent%2)
        return (((ans*ans)%mod)*baza)%mod;

    return (ans*ans)%mod;
}
long long comb(long long k, long long n)
{
    long long A=1, B=1;
    for(long long i=n-k+1;i<=n;i++)
    {
        A*=i;
        A%=mod;
    }

    for(long long i=1;i<=k;i++)
    {
        B*=i;
        B%=mod;
    }

    return (A*(put(B, mod-2)))%mod;
}
int main()
{
    cin>>n>>m;
    ans=comb(n-1, m);
    ans*=n-2;
    ans%=mod;
    ans*=put(2, n-3);
    ans%=mod;
    cout<<ans;
    return 0;
}
