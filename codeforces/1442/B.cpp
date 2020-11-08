#include <iostream>
#define mod 998244353

using namespace std;
long long t,n,k,i,ans,nr,x;
long long a[200005];
long long val[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;

        val[0]=n+1;
        for(i=1;i<=n;i++)
            val[i]=0;

        for(i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=0;
        
        for(i=1;i<=k;i++)
        {
            cin>>x;
            val[x]=i;
        }

        ans=1;
        for(i=1;i<=n;i++)
        {
            if(!val[a[i]])
                continue;

            nr=0;
            if(val[a[i-1]]<val[a[i]])
                nr++;
            if(val[a[i+1]]<val[a[i]])
                nr++;

            ans*=nr;
            ans%=mod;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
