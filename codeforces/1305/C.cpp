#include <iostream>
#include <cmath>

using namespace std;
long long ans,n,m,i,j,a[1005];
int main()
{
    cin>>n>>m;
    if(n>m)
    {
        cout<<0;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ans=1;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            ans*=(long long)abs(a[j]-a[i])%m;
            ans%=m;
        }
    }
    cout<<ans;
    return 0;
}
