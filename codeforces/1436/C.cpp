#include <iostream>
#define mod 1000000007

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
long long aranj(long long k, long long n)
{
    if(k>n)
        return 0;

    long long ans=1;
    for(long long i=n-k+1;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }

    return ans;
}
long long fact(long long n)
{
    long long ans=1;
    for(long long i=1;i<=n;i++)
    {
        ans*=i;
        ans%=mod;
    }
    return ans;
}
long long n,x,pos,nrmic,nrmare,ans;
long long st,dr,mij;
int main()
{
    cin>>n>>x>>pos;
    st=0;
    dr=n;

    while(st<dr)
    {
        mij=(st+dr)/2;
        if(mij<=pos)
        {
            if(mij<pos)
                nrmic++;
            st=mij+1;
        }
        else
        {
            nrmare++;
            dr=mij;
        }
    }

    ans=aranj(nrmic, x-1);
    ans*=aranj(nrmare, n-x);
    ans%=mod;
    ans*=fact(n-nrmic-nrmare-1);
    ans%=mod;

    cout<<ans;
    return 0;
}
