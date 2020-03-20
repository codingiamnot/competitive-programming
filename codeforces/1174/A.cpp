#include <bits/stdc++.h>

using namespace std;
int i,n,a[2005];
bool ok;
int main()
{
    cin>>n;
    n*=2;
    for(i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1, a+n+1);

    ok=false;
    for(i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1])
            ok=true;
    }

    if(ok)
    {
        for(i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
