#include <bits/stdc++.h>

using namespace std;

struct pos
{
    int mini=0, maxi=0, sum=0;
};

int t,n,q,i;
char ch;
int l,r,mini,maxi,sum;
int a[200005];
pos dpl[200005];
pos dpr[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>q;
        for(i=1;i<=n;i++)
        {
            cin>>ch;
            if(ch=='-')
                a[i]=-1;
            else
                a[i]=1;
        }

        dpl[0].sum=dpl[0].mini=dpl[0].maxi=0;

        for(i=1;i<=n;i++)
        {
            dpl[i].sum=dpl[i-1].sum+a[i];
            dpl[i].maxi=max(dpl[i-1].maxi, dpl[i].sum);
            dpl[i].mini=min(dpl[i-1].mini, dpl[i].sum);
        }

        dpr[n+1].sum=dpr[n+1].mini=dpr[n+1].maxi=0;

        for(i=n;i>=1;i--)
        {
            dpr[i].sum=dpr[i+1].sum+a[i];
            dpr[i].maxi=max(0, dpr[i+1].maxi+a[i]);
            dpr[i].mini=min(0, dpr[i+1].mini+a[i]);
        }

        while(q)
        {
            q--;
            cin>>l>>r;
            mini=dpl[l-1].mini;
            maxi=dpl[l-1].maxi;
            sum=dpl[l-1].sum;

            //cout<<mini<<' '<<maxi<<' '<<sum<<'\n';
            //cout<<dpr[r+1].mini<<' '<<dpr[r+1].maxi<<'\n';

            mini=min(mini, sum+dpr[r+1].mini);
            maxi=max(maxi, sum+dpr[r+1].maxi);

            cout<<maxi-mini+1<<'\n';
        }
    }
    return 0;
}
