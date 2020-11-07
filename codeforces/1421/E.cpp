#include <bits/stdc++.h>

using namespace std;
long long n,sum,x,y,ans,i;
long long a[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2)
            x+=a[i];
        else
            y+=a[i];
        sum+=a[i];
    }
    sort(a+1, a+n+1);

    ans=-1e18;
    if(n%3==1)
        ans=sum;

    for(i=1;i<=n;i++)
    {
        sum-=2*a[i];

        if((n+i)%3==1)
        {
            if(sum==x-y || sum==y-x)
                ans=max(ans, sum+2*a[i]-2*a[i+1]);
            else
                ans=max(ans, sum);
        }
    }

    cout<<ans;
    return 0;
}
