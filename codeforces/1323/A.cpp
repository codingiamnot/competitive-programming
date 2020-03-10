#include <iostream>

using namespace std;
int t,n,i,a[105],nr,nri,nrp;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        nrp=0;
        nri=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]%2)
                nri++;
            else
                nrp++;
        }

        if(nrp)
        {
            cout<<1<<'\n';
            for(i=1;i<=n;i++)
            {
                if(a[i]%2==0)
                {
                    cout<<i;
                    break;
                }
            }
            cout<<'\n';
            continue;
        }

        if(nri>1)
        {
            cout<<2<<'\n';
            nr=0;
            for(i=1;i<=n;i++)
            {
                if(a[i]%2)
                {
                    cout<<i<<' ';
                    nr++;
                }

                if(nr==2)
                {
                    break;
                }
            }
            cout<<'\n';
            continue;
        }

        cout<<"-1\n";
    }
    return 0;
}
