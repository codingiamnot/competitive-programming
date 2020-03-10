#include <bits/stdc++.h>

using namespace std;
int i,t,n,a[105];
bool comp(int a, int b)
{
    return a>b;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1, comp);

        for(i=1;i<=n;i++)
            cout<<a[i]<<' ';

        cout<<'\n';
    }
    return 0;
}
