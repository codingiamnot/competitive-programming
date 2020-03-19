#include <iostream>

using namespace std;
int dif,maxi,i,n,ans[200005];
int main()
{
    cin>>n;
    maxi=0;
    for(i=1;i<=n;i++)
    {
        cin>>dif;
        ans[i]=maxi+dif;
        maxi=max(maxi, ans[i]);
    }
    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
