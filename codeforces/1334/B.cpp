#include <bits/stdc++.h>

using namespace std;
long long t,n,x,i,sum,ans;
long long a[100005];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>x;
        for(i=1;i<=n;i++)
            cin>>a[i];

        sort(a+1, a+n+1);

        ans=0;
        sum=0;
        for(i=n;i>=1;i--)
        {
            sum+=a[i];
            if(sum>=x*(n-i+1))
                ans++;
            else
                break;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
