#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long n,m,k,i,p,t,ans;
long long a[200005];

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
    if(k>n)
        return 0;

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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;

        cin>>n>>m>>k;
        for(i=1;i<=n;i++)
            cin>>a[i];

        ans=0;
        sort(a+1, a+n+1);

        /*
        for(i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
        */

        p=1;
        for(i=1;i<=n;i++)
        {
            while(p<n && a[p+1]<=a[i]+k)
                p++;

            //cout<<i<<' '<<p<<'\n';

            ans+=comb(m-1, p-i);
            ans%=mod;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
