#include <bits/stdc++.h>

using namespace std;
long long comb(long long k, long long n)
{
    long long ans=1;
    for(long long i=n-k+1;i<=n;i++)
        ans*=i;
    for(long long i=1;i<=k;i++)
        ans/=i;

    return ans;
}
long long f(long long n)
{
    if(n==1)
        return 1;

    long long ans=n-1;

    for(long long i=1;i<=n-2;i++)
        ans*=i;

    return ans;
}
long long n,ans;
int main()
{
    cin>>n;
    ans=comb(n/2-1, n-1);
    ans*=f(n/2);
    ans*=f(n/2);
    cout<<ans;
    return 0;
}
