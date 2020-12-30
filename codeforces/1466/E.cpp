#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long t,n,i,b;
long long cnt,sum,ans;
long long v[500005];
long long s[500005];
long long s2[500005];

long long put(long long baza, long long exp)
{
    if(!exp)
        return 1;

    long long ans=put(baza, exp/2);
    ans*=ans;
    ans%=mod;

    if(exp%2)
    {
        ans*=baza;
        ans%=mod;
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=0;

        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            s[i]=0;
            s2[i]=0;
        }

        for(b=0;b<60;b++)
        {
            cnt=0;

            for(i=1;i<=n;i++)
                if((v[i]>>b)&1)
                    cnt++;

            for(i=1;i<=n;i++)
            {
                if((v[i]>>b)&1)
                    s[i]+=(n*put(2, b))%mod;
                else
                    s[i]+=(cnt*put(2, b))%mod;

                s[i]%=mod;
            }

            for(i=1;i<=n;i++)
            {
                if((v[i]>>b)&1)
                {
                    s2[i]+=(cnt*put(2, b))%mod;
                    s2[i]%=mod;
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            ans+=(s[i]*s2[i])%mod;
            ans%=mod;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
