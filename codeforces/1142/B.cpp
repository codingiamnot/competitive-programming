#include <iostream>

using namespace std;
int n,m,i,x,q,st,dr,b;
int perm[200005];
int a[200005];
int lift[200005][35];
int dp[200005];
int last[200005];
int anc(int poz, int k)
{
    if(!k)
        return poz;

    for(int b=0;b<=32;b++)
    {
        if((k>>b)&1)
            return anc(lift[poz][b], k-(1<<b));
    }
}
/*
int anc(int poz, int k)
{
    if(!k)
        return poz;

    return anc(lift[poz][0], k-1);
}
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        perm[x]=i;
    }

    for(i=1;i<=m;i++)
    {
        cin>>x;
        a[i]=perm[x];
    }

    for(i=1;i<=m;i++)
    {
        if(a[i]==1)
            lift[i][0]=last[n];
        else
            lift[i][0]=last[a[i]-1];

        last[a[i]]=i;
    }

    for(i=1;i<=m;i++)
    {
        for(b=1;b<=32;b++)
        {
            lift[i][b]=lift[lift[i][b-1]][b-1];
            if(!lift[i][b])
                break;
        }
    }

    for(i=1;i<=m;i++)
        dp[i]=max(dp[i-1], anc(i, n-1));


    while(q)
    {
        q--;
        cin>>st>>dr;
        if(dp[dr]>=st)
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
