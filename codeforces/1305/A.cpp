#include <bits/stdc++.h>

using namespace std;
int t,n,i,a[106],b[105];
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

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for(i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<'\n';

    for(i=1;i<=n;i++)
        cout<<b[i]<<' ';
    cout<<'\n';
    }
    return 0;
}
