#include <bits/stdc++.h>

using namespace std;

long long n,i,j,b,sum,maxi;
long long a[200005];
set<pair<long long, long long>> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        for(b=0;b<=30;b++)
        {
            if((1<<b)>a[i])
            {
                maxi=(1<<b);
                break;
            }
        }
        sum=0;
        for(j=i+2;j<=n;j++)
        {
            sum+=a[j-1];
            if(sum>maxi)
                break;

            if(sum==(a[i]^a[j]))
                ans.insert({i, j});
        }
    }

    reverse(a+1, a+n+1);
    for(i=1;i<=n;i++)
    {
        for(b=0;b<=30;b++)
        {
            if((1<<b)>a[i])
            {
                maxi=(1<<b);
                break;
            }
        }
        sum=0;
        for(j=i+2;j<=n;j++)
        {
            sum+=a[j-1];
            if(sum>maxi)
                break;

            if(sum==(a[i]^a[j]))
                ans.insert({n-j+1, n-i+1});
        }
    }

    cout<<ans.size();
    return 0;
}
