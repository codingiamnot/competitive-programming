#include <bits/stdc++.h>

using namespace std;
int n,i,gcd,nr,maxi,ans;
int a[300005];
int ciur[15000000];
int fr[15000000];
void sieve(int maxi)
{
    for(long long i=2;i<=maxi;i++)
    {
        if(ciur[i])
            continue;

        ciur[i]=i;
        for(long long j=i*i;j<=maxi;j+=i)
            ciur[j]=i;
    }
}
void fact(int x, int avoid)
{
    if(x==1)
        return;

    if(ciur[x]!=avoid)
    {
        fr[ciur[x]]++;
        ans=max(ans, fr[ciur[x]]);
    }
    fact(x/ciur[x], ciur[x]);
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        gcd=__gcd(gcd, a[i]);
    }

    for(i=1;i<=n;i++)
    {
        a[i]/=gcd;
        maxi=max(maxi, a[i]);
    }
    sieve(maxi);

    for(i=1;i<=n;i++)
        fact(a[i], 0);

    if(ans)
        cout<<n-ans;
    else
        cout<<-1;
    return 0;
}
