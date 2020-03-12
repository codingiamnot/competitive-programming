#include <iostream>

using namespace std;
int t,n,i,x;
bool okp,oki;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        okp=false;
        oki=false;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x%2)
                oki=true;
            else
                okp=true;
        }

        if(oki && okp)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    return 0;
}
