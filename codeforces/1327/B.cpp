#include <iostream>

using namespace std;
int t,i,k,n,j,x,nem;
bool p[100005];
bool optim,ok;
int main()
{
    cin>>t;
    while(t)
    {
        t--;

        for(i=1;i<=n;i++)
            p[i]=false;
        optim=true;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            ok=false;
            cin>>k;
            for(j=1;j<=k;j++)
            {
                cin>>x;
                if(!p[x] && !ok)
                {
                    p[x]=true;
                    ok=true;
                }
            }

            if(!ok)
            {
                optim=false;
                nem=i;
            }
        }

        if(optim)
        {
            cout<<"OPTIMAL\n";
        }
        else
        {
            cout<<"IMPROVE\n";
            cout<<nem<<' ';
            for(i=1;i<=n;i++)
            {
                if(!p[i])
                {
                    cout<<i<<'\n';
                    break;
                }
            }
        }
    }
    return 0;
}
