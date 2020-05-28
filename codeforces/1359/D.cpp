#include <iostream>

using namespace std;
int n,i,s,ans,maxi;
int a[100005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(maxi=0;maxi<=30;maxi++)
    {
        s=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]>maxi)
                continue;
            s+=a[i];
            if(s<=0)
                s=0;
            ans=max(ans, s-maxi);
        }
    }
    cout<<ans;
    return 0;
}
