#include <bits/stdc++.h>

using namespace std;

int t,n,m,i,nr;
int a[100005];
double ans, p, prod;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(12);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        for(i=1;i<=n;i++)
            cin>>a[i];

        nr=n;
        while(nr>0 && a[nr]==nr)
            nr--;

        ans=0;
        prod=1;
        while(m)
        {
            m--;
            cin>>i>>p;
            if(i>=nr)
            {
                ans+=prod*p;
                prod*=(1-p);
            }
        }

        if(!nr)
            cout<<"1\n";
        else
            cout<<ans<<'\n';
    }
    return 0;
}
