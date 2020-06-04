#include <iostream>

using namespace std;
long long t,ans,nr,a,b,d;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ans=0;
        nr=0;
        cin>>a>>b;
        if(a>b)
            swap(a, b);

        if(b%a)
        {
            cout<<-1<<'\n';
            continue;
        }
        d=b/a;
        while(d%2==0)
        {
            nr++;
            d/=2;
        }
        if(d!=1)
        {
            cout<<-1<<'\n';
            continue;
        }

        ans+=nr/3;
        nr=nr%3;
        ans+=nr/2;
        nr=nr%2;
        ans+=nr;
        cout<<ans<<'\n';
    }
    return 0;
}
