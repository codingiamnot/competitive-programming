#include <bits/stdc++.h>

using namespace std;
int t,i,ans,last,n;
int a[200005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        ans=0;
        last=0;

        for(i=1;i<=n;i++)
        {
            if(i-last>=a[i])
            {
                last=i;
                ans++;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
