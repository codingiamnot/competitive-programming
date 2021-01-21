#include <iostream>

using namespace std;

long long t,k,ans,i,j;
long long ciur[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(long long i=2;i<=2e5;i++)
    {
        if(ciur[i]==0)
        {
            for(long long j=i*i;j<=2e5;j+=i)
                ciur[j]=1;
        }
    }

    cin>>t;
    while(t)
    {
        t--;
        cin>>k;

        ans=1;
        for(i=ans+k;i<=2e5;i++)
        {
            if(!ciur[i])
            {
                ans*=i;
                break;
            }
        }

        for(i=ans+k;i<=2e5;i++)
        {
            if(!ciur[i])
            {
                ans*=i;
                break;
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
