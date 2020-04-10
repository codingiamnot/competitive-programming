#include <iostream>

using namespace std;
int t,n,i,x,y,lx,ly;
bool ok;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ok=true;
        lx=0;
        ly=0;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            if(x<lx || y<ly)
                ok=false;
            if(x-lx<y-ly)
                ok=false;

            lx=x;
            ly=y;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
