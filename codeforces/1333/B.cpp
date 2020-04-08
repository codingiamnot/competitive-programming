#include <bits/stdc++.h>

using namespace std;
int t,n,i;
int a[100005],b[100005];
bool ok,oks,okb;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ok=true;
        oks=false;
        okb=false;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
            cin>>b[i];

        for(i=1;i<=n;i++)
        {
            if(a[i]!=b[i])
            {
                if(a[i]<b[i] && !oks)
                    ok=false;
                if(a[i]>b[i] && !okb)
                    ok=false;
            }

            if(a[i]==1)
                oks=true;
            if(a[i]==-1)
                okb=true;

        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
