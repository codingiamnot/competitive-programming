#include <iostream>
#define mod 998244353

using namespace std;
long long put(long long exp)
{
    if(exp==0)
        return 1;
    if(exp==1)
        return 10;

    long long val=put(exp/2);

    if(exp%2)
        return (((val*val)%mod)*10)%mod;
    else
        return (val*val)%mod;
}
long long n,A,B,ans;
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        if(i==n)
        {
            cout<<10;
            continue;
        }

        A=10*(n-i-1);
        A%=mod;
        A*=9*9;
        A%=mod;
        A*=put(n-i-2);
        A%=mod;

        B=20*9;
        B*=put(n-i-1);
        B%=mod;

        ans=(A+B)%mod;

        cout<<ans<<' ';
    }
    return 0;
}
