#include <bits/stdc++.h>

using namespace std;
long long t,n,x,s,m,i;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        s=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            s+=x;
        }

        if(s==m)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
