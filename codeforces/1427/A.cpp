#include <bits/stdc++.h>

using namespace std;
int t,n,i,s;
int a[105];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        s=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        sort(a+1, a+n+1);

        if(!s)
        {
            cout<<"NO\n";
            continue;
        }

        if(s>0)
            reverse(a+1, a+n+1);

        cout<<"YES\n";
        for(i=1;i<=n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
