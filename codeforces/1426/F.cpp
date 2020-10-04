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
long long a,ab,abc,nr,n,i;
char ch;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ch;
        if(ch=='a')
            a+=put(3, nr);
        if(ch=='b')
            ab+=a;
        if(ch=='c')
            abc+=ab;
        if(ch=='?')
        {
            abc=ab+3*abc;
            ab=a+3*ab;
            a=put(3, nr)+3*a;

            nr++;
        }

        a%=mod;
        ab%=mod;
        abc%=mod;
    }

    cout<<abc;
    return 0;
}
