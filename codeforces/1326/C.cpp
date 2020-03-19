#include <iostream>
#define mod 998244353

using namespace std;
long long n,k,x,ans,i,last;
int main()
{
    cin>>n>>k;
    ans=1;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x>=n-k+1)
        {
            if(last)
            {
                ans*=i-last;
                ans%=mod;
            }
            last=i;
        }
    }
    cout<<n*(n+1)/2-(n-k)*(n-k+1)/2<<' '<<ans;
    return 0;
}
