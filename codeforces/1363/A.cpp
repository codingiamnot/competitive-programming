#include <iostream>

using namespace std;
long long t,n,a,nri,nrp,i,x;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>a;
        nri=nrp=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x%2)
                nri++;
            else
                nrp++;
        }

        if(!nri)
        {
            cout<<"No\n";
            continue;
        }
        if(!nrp && a%2==0)
        {
            cout<<"No\n";
            continue;
        }
        if(a==n && nri%2==0)
        {
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";
    }
    return 0;
}
