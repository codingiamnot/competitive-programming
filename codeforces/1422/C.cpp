#include <iostream>
#define mod 1000000007

using namespace std;
long long put(long long baza, long long exp)
{
    if(exp==0)
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
long long n,i,ans,nans,p;
long long inv2, inv9, inv10, inv81;
char ch;
string s;
long long a[100005];
long long comb(long long x)
{
    long long ans=x*(x-1);
    ans%=mod;
    ans*=inv2;
    ans%=mod;

    ans+=x;
    ans%=mod;

    return ans;
}
int main()
{
    inv2=put(2, mod-2);
    inv9=put(9, mod-2);
    inv10=put(10, mod-2);
    inv81=put(81, mod-2);

    cin>>s;
    n=s.size();
    for(i=1;i<=n;i++)
    {
        ch=s[i-1];
        a[i]=ch-'0';
    }

    for(i=1;i<=n;i++)
    {
        p=n-i;
        //cout<<i<<' '<<p<<'\n';

        nans=(((put(10, p)*p)%mod)*inv9)%mod;
        nans%=mod;
        //cout<<nans<<'\n';

        nans-=(put(10, p)*inv81)%mod;
        if(nans<0)
            nans+=mod;

        nans+=inv81;
        nans%=mod;

        nans+=put(10, p)*comb(n-p-1);
        nans%=mod;
        //cout<<nans<<'\n';


        ans+=(nans*a[i])%mod;
        ans%=mod;
    }

    cout<<ans;
    return 0;
}
