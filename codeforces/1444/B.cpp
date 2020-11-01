#include <bits/stdc++.h>
#define mod 998244353

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
long long comb(long long k, long long n)
{
    long long a=1;
    for(long long i=n-k+1;i<=n;i++)
    {
        a*=i;
        a%=mod;
    }

    long long b=1;
    for(long long i=1;i<=k;i++)
    {
        b*=i;
        b%=mod;
    }

    return (a*put(b, mod-2))%mod;
}
long long n,i,ans;
long long a[300005];
int main()
{
    cin>>n;
    for(i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1, a+2*n+1);

    for(i=1;i<=n;i++)
    {
        ans-=a[i];
        ans%=mod;
        if(ans<0)
            ans+=mod;
    }
    for(i=n+1;i<=2*n;i++)
    {
        ans+=a[i];
        ans%=mod;
    }

    ans*=comb(n, 2*n);
    ans%=mod;

    cout<<ans;
    return 0;
}
