#include <bits/stdc++.h>

using namespace std;
long long t,a,b,q,l,r,lcm,ans,rb,i;
long long nrmod(long long rest,long long mod)
{
    long long ans=(r-r%mod-l+l%mod)/mod;
    if(r%mod>=rest)
        ans++;
    if(l%mod>rest)
        ans--;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t)
    {
        t--;
        cin>>a>>b>>q;
        if(a>b)
            swap(a,b);
        lcm=a*b/__gcd(a,b);
        for(i=1;i<=q;i++)
        {
            cin>>l>>r;
            ans=0;
            for(rb=0;rb<b;rb++)
            {
                ans+=nrmod(rb, b)-nrmod(rb, lcm);
                //cout<<rb<<' '<<nrmod(rb, b)<<' '<<nrmod(rb, lcm)<<'\n';
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
