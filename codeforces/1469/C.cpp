#include <iostream>

using namespace std;

int t,n,k,st,dr,i;
bool ok;
int a[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;

        for(i=1;i<=n;i++)
            cin>>a[i];

        st=a[1];
        dr=a[1];
        ok=true;

        for(i=2;i<=n;i++)
        {
            st=max(st-k+1, a[i]);
            dr=min(dr+k-1, a[i]+k-1);

            if(st>dr)
                ok=false;
        }

        if(st==a[n] && ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
