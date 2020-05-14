#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
long long n,d,q,ans,x,y;
long long a,b,c,nra,nrb;
long long fact(long long n)
{
    long long ans=1;
    for(long long i=2;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }

    return ans;
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
vector <long long> prime;
int main()
{
    cin>>n;
    d=2;
    while(d*d<=n)
    {
        if(n%d==0)
        {
            prime.push_back(d);
            while(n%d==0)
                n/=d;
        }
        d++;
    }
    if(n!=1)
        prime.push_back(n);

    cin>>q;
    while(q)
    {
        q--;
        cin>>x>>y;
        c=1;
        a=0;
        b=0;
        for(long long prim : prime)
        {
            nra=0;
            while(x%prim==0)
            {
                x/=prim;
                nra++;
            }

            nrb=0;
            while(y%prim==0)
            {
                y/=prim;
                nrb++;
            }

            if(nra>nrb)
                a+=nra-nrb;
            else
                b+=nrb-nra;

            c*=fact(abs(nra-nrb));
            c%=mod;
        }

        ans=(fact(a)*fact(b))%mod;
        ans*=put(c, mod-2);
        ans%=mod;
        cout<<ans<<'\n';
    }
    return 0;
}
