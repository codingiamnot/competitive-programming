#include <iostream>

using namespace std;
long long t,n,ans,nans,i;
long long s[1005];
string v;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>v;
        n=v.size();
        ans=n+1;
        for(i=1;i<=n;i++)
        {
            s[i]=s[i-1]+v[i-1]-'0';
        }
        for(i=1;i<=n;i++)
        {
            //cout<<i<<' '<<s[i]+n-i-s[n]+s[i]<<' '<<i-s[i]+n-i<<'\n';
            ans=min(ans, s[i]+n-i-s[n]+s[i]);
            ans=min(ans, i-s[i]+s[n]-s[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
