#include <bits/stdc++.h>

using namespace std;
int n,i,poz;
int a[25],c[25];
map <int, int> m;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i]=a[i];
    }

    sort(c+1, c+n+1);

    for(i=1;i<=n;i++)
        m[c[i]]=i;

    for(i=1;i<=n;i++)
    {
        poz=m[a[i]];
        poz++;
        if(poz==n+1)
            poz=1;
        cout<<c[poz]<<' ';
    }
    return 0;
}
