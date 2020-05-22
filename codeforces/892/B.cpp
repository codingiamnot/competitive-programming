#include <iostream>

using namespace std;
int n,i,ans,maxi;
int a[1000005];
int main()
{
    cin>>n;
    ans=n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(i=n;i>=1;i--)
    {
        maxi--;
        if(maxi>=0)
            ans--;
        maxi=max(maxi, a[i]);
    }

    cout<<ans;
    return 0;
}
