#include <bits/stdc++.h>

using namespace std;
int i,n,a[100005];
bool oki,okp;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2)
            oki=true;
        else
            okp=true;
    }

    if(okp && oki)
        sort(a+1, a+n+1);

    for(i=1;i<=n;i++)
        cout<<a[i]<<' ';
    return 0;
}
