#include <iostream>

using namespace std;
int j,n,i,t,a[5005];
bool ok;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ok=false;
        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=1;i<=n;i++)
            for(j=i+2;j<=n;j++)
                if(a[i]==a[j])
        {
            ok=true;
            break;
        }

        if(ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
