#include <bits/stdc++.h>

using namespace std;
int t,n,i;
int a[105],b[105],c[105],ans[105];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            cin>>b[i];
        for(i=1;i<=n;i++)
            cin>>c[i];

        for(i=1;i<n;i++)
        {
            if(a[i]!=ans[i-1])
            {
                ans[i]=a[i];
                continue;
            }

            if(b[i]!=ans[i-1])
            {
                ans[i]=b[i];
                continue;
            }

            if(c[i]!=ans[i-1])
            {
                ans[i]=c[i];
                continue;
            }
        }

        if(a[n]!=ans[1] && a[n]!=ans[n-1])
            ans[n]=a[n];
        else if(b[n]!=ans[1] && b[n]!=ans[n-1])
            ans[n]=b[n];
        else
            ans[n]=c[n];

        for(i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
