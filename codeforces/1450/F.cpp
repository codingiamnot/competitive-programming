#include <iostream>

using namespace std;

int t,n,i,k,maxi,ans;
int a[100005];
int fr[100005];

void add(int x)
{
    fr[x]++;
    if(fr[x]>maxi)
        maxi=fr[x];
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

        maxi=0;
        for(i=1;i<=n;i++)
            fr[i]=0;

        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            add(a[i]);
        }

        if(maxi>(n+1)/2)
        {
            cout<<"-1\n";
            continue;
        }

        k=0;
        maxi=0;
        for(i=1;i<=n;i++)
            fr[i]=0;

        add(a[1]);
        add(a[n]);
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                add(a[i]);
                add(a[i+1]);
                k++;
            }
        }

        //cout<<maxi<<' ';
        ans=k+max(0, maxi-k-2);

        if(ans>=n)
            cout<<"-1\n";
        else
            cout<<ans<<'\n';
    }
    return 0;
}
