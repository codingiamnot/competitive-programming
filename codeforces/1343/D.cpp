#include <iostream>

using namespace std;
int t,ans,n,i,k,pretc,mini,maxi;
int pret[400005];
int a[200005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>k;
        ans=n;
        for(i=1;i<=2*k;i++)
            pret[i]=0;

        for(i=1;i<=n;i++)
            cin>>a[i];
        for(i=1;i<=n/2;i++)
        {
            mini=min(a[i], a[n-i+1]);
            maxi=max(a[i], a[n-i+1]);

            pret[mini+1]--;
            pret[a[i]+a[n-i+1]]--;
            pret[a[i]+a[n-i+1]+1]++;
            pret[maxi+k+1]++;
        }

        pretc=n;
        for(i=1;i<=2*k;i++)
        {
            pretc+=pret[i];
            ans=min(ans, pretc);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
