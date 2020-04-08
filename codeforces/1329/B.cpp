#include <iostream>

using namespace std;
long long t,d,m,ans,val;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>d>>m;
        ans=1;
        val=1;
        while(true)
        {
            if(val*2>d)
            {
                ans*=d-val+2;
                ans%=m;
                break;
            }

            ans*=val+1;
            ans%=m;
            val*=2;
        }
        ans--;
        if(ans<0)
            ans+=m;
        cout<<ans<<'\n';
    }
    return 0;
}
