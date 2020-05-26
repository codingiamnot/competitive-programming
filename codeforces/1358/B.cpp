#include <bits/stdc++.h>

using namespace std;
long long t,n,x,ans,i;
int a[100005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=1;
        for(i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1, a+n+1);

        for(i=1;i<=n;i++)
        {
            if(i>=a[i])
                ans=i+1;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
