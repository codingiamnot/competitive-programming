#include <bits/stdc++.h>

using namespace std;
int n,i,maxi,idmax,nr,ans;
int a[200005];
int v[200005];
int fr[400005];

int solve(int x)
{
    for(int i=1;i<=n;i++)
        if(a[i]==x)
            v[i]=-1;

    for(int i=0;i<=2*n;i++)
        fr[i]=-1;
    fr[n]=0;

    int sum=0;
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        sum+=v[i];

        if(sum+n>=0 && sum+n<=2*n)
        {
            if(fr[sum+n]!=-1)
                ans=max(ans, i-fr[sum+n]);

            else
                fr[sum+n]=i;
        }
    }

    for(int i=1;i<=n;i++)
        if(a[i]==x)
            v[i]=0;

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];

    for(i=1;i<=n;i++)
    {
        fr[a[i]]++;
        if(fr[a[i]]>maxi)
        {
            maxi=fr[a[i]];
            nr=0;
            idmax=a[i];
        }
        if(fr[a[i]]==maxi)
            nr++;
    }

    if(nr>2)
    {
        cout<<n;
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        if(a[i]==idmax)
            v[i]=1;
    }

    for(i=1;i<=100;i++)
    {
        if(i==idmax)
            continue;

        ans=max(ans, solve(i));
    }
    cout<<ans;
    return 0;
}
