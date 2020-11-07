#include <iostream>

using namespace std;
int t,n,i;
bool ok;
int v[300005],a[300005],b[300005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>v[i];

        ok=true;
        a[0]=1e9;
        for(i=1;i<=n;i++)
        {
            a[i]=min(a[i-1], v[i]-b[i-1]);
            b[i]=v[i]-a[i];

            if(a[i]<0 || b[i]<0)
                ok=false;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}
