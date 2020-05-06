#include <iostream>

using namespace std;
long long n,x,y,val,ans,i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        val=y+x;
        ans=max(ans, val);
    }
    cout<<ans;
    return 0;
}
