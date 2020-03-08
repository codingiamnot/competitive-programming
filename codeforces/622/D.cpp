#include <iostream>

using namespace std;
int n,i,ans[1000005];
int main()
{
    cin>>n;
    for(i=1;i<n;i+=2)
    {
        ans[i/2+1]=i;
        ans[i/2+1+n-i]=i;
    }
    for(i=2;i<n;i+=2)
    {
        ans[i/2+n]=i;
        ans[i/2+n+n-i]=i;
    }
    for(i=1;i<=2*n;i++)
    {
        if(!ans[i])
            ans[i]=n;
    }
    for(i=1;i<=2*n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
