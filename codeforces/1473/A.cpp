#include <bits/stdc++.h>

using namespace std;

int t,n,d,i;
int a[5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>d;
        for(i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1, a+n+1);

        if(a[1]+a[2]<=d)
        {
            cout<<"YES\n";
            continue;
        }

        if(a[n]<=d)
        {
            cout<<"YES\n";
            continue;
        }

        cout<<"NO\n";
    }
    return 0;
}
