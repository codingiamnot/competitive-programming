#include <iostream>

using namespace std;
struct pos
{
    long long l,r,c;
};
long long n,k,i,j,tot,rem,nrem,nmag,ans;
long long dp[2005];
pos v[2005];
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>v[i].l>>v[i].r>>v[i].c;

    for(i=1;i<=n;i++)
        dp[i]=1e18;

    ans=1e18;
    for(i=1;i<=n;i++)
    {
        rem=k;
        tot=dp[i-1];

        for(j=i;j<=n;j++)
        {
            nmag=(max((long long)0, v[j].c-rem)+k-1)/k;

            if(nmag>v[j].r-v[j].l)
                break;

            nrem=rem+k*nmag-v[j].c;
            tot+=v[j].c;

            if(j<n)
            {
                if(v[j].l + nmag < v[j+1].l)
                    dp[j]=min(dp[j], tot+nrem);
            }
            else
                ans=min(ans, tot);

            rem=nrem;
        }
    }

    if(ans==1e18)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
