#include <bits/stdc++.h>

using namespace std;
long long t,n,i,nrp,nri;
bool ok;
long long a[55];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        nri=0;
        nrp=0;
        ok=false;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        for(i=1;i<=n;i++)
        {
            if(a[i]%2)
                nri++;
            else
                nrp++;

            if(i>1 && a[i]==a[i-1]+1)
            {
                ok=true;
            }
        }

        if(nrp%2==0 && nri%2==0)
        {
            cout<<"YES\n";
            continue;
        }
        if(nrp%2 && nri%2 && ok)
        {
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}
