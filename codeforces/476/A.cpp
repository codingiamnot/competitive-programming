#include <iostream>

using namespace std;
long long n,a,b,ans,m;
int main()
{
    ans=1e18;
    cin>>n>>m;
    for(a=0;2*a<=n;a++)
    {
        b=n-2*a;
        if((a+b)%m==0)
        {
            ans=min(ans, a+b);
        }
    }
    if(ans==1e18)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
