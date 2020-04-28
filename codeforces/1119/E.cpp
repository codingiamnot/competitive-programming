#include <iostream>

using namespace std;
long long n,i,x,nr1,ans,nrnow;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        nrnow=min(nr1, x/2);
        ans+=nrnow;
        nr1-=nrnow;
        x-=2*nrnow;

        ans+=x/3;
        x%=3;

        nr1+=x;
    }
    cout<<ans;
    return 0;
}
