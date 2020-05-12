#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
struct val
{
    long long mini=1e8, mini2=1e8;
    long long cnt=0;
    void upd(long long nr)
    {
        cnt++;
        if(nr<mini)
        {
            mini2=mini;
            mini=nr;
        }
        else
        {
            mini2=min(mini2, nr);
        }
    }
};
long long n,i,x,d,ans,nr;
map <long long, val> m;
long long put(long long baza, int exp)
{
    if(exp==0)
        return 1;
    if(exp==1)
        return baza;

    long long ans=put(baza, exp/2);

    if(exp%2)
        return ans*ans*baza;
    return ans*ans;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        d=2;
        while(d*d<=x)
        {
            nr=0;
            while(x%d==0)
            {
                x/=d;
                nr++;
            }
            m[d].upd(nr);
            d++;
        }

        if(x!=1)
        {
            m[x].upd(1);
        }
    }

    ans=1;
    for(auto it : m)
    {
        if(it.s.cnt==n)
            ans*=put(it.f, it.s.mini2);
        if(it.s.cnt==n-1)
            ans*=put(it.f, it.s.mini);
    }
    cout<<ans;
    return 0;
}
