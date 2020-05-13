#include <iostream>
#define mod 998244353

using namespace std;
long long n,m,l,r,ans,e,o;
long long par(int x, int y)
{
    if(x%2==0)
        x--;

    if(y%2)
        y--;

    return (y-x+1)/2;
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
int main()
{
    cin>>n>>m>>l>>r;

    e=par(l, r);
    o=r-l+1-e;

    if(n*m%2)
    {
        ans=put((e+o)%mod, n*m);
    }
    else
    {
        ans=put((e+o)%mod, n*m)+put(e-o, n*m);
        ans%=mod;
        ans*=put(2, mod-2);
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
