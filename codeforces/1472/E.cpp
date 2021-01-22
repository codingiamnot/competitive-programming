#include <bits/stdc++.h>

using namespace std;

int t,n,i;
int a[200005];
int b[200005];
int v[200005];
int ans[200005];

int mini[200005];
int last[200005];

bool comp(int x, int y)
{
    return a[x]<a[y];
}

int cb(int x)
{
    int st=1, dr=n;
    int mij, last=0;

    while(st<=dr)
    {
        mij=(st+dr)/2;

        if(a[v[mij]]<x)
        {
            last=mij;
            st=mij+1;
        }
        else
            dr=mij-1;
    }

    return last;
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
        for(i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i];
            v[i]=i;
            ans[i]=-1;
        }

        sort(v+1, v+n+1, comp);

        mini[0]=1e9;
        for(i=1;i<=n;i++)
        {
            mini[i]=mini[i-1];
            last[i]=last[i-1];

            if(b[v[i]]<mini[i])
            {
                mini[i]=b[v[i]];
                last[i]=v[i];
            }
        }

        for(i=1;i<=n;i++)
        {
            int p=cb(a[v[i]]);
            if(mini[p] < b[v[i]])
                ans[v[i]]=last[p];

            p=cb(b[v[i]]);
            if(mini[p] < a[v[i]])
                ans[v[i]]=last[p];
        }

        for(i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    return 0;
}
