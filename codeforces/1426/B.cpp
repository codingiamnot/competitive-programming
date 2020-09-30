#include <bits/stdc++.h>

using namespace std;
int i,t,n,m,a1,a2,a3,a4;
bool ok;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;

        ok=false;
        for(i=1;i<=n;i++)
        {
            cin>>a1>>a2>>a3>>a4;
            if(a2==a3)
                ok=true;
        }

        if(m%2)
            ok=false;

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
