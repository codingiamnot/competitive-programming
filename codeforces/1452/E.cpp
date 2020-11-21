#include <bits/stdc++.h>

using namespace std;

struct seg
{
    int l, r;
    bool operator<(seg b) const
    {
        return l+r < b.l+b.r;
    }
};

int cst(int a, int b, int c, int d)
{
    int l=max(a, c);
    int r=min(b, d);

    return max(0, r-l+1);
}

int n,m,k,i,j;
long long ansl, ansr, ans;
seg v[2005];
long long a[2005][2005];
long long s[2005][2005];
int main()
{
    cin>>n>>m>>k;

    for(i=1;i<=m;i++)
        cin>>v[i].l>>v[i].r;

    sort(v+1, v+m+1);

    /*
    for(i=1;i<=m;i++)
        cout<<v[i].l<<' '<<v[i].r<<'\n';
    */

    for(i=1;i+k-1<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            a[i][j]=cst(i, i+k-1, v[j].l, v[j].r);
            s[i][j]=s[i][j-1]+a[i][j];
        }
    }

    /*
    for(i=1;i+k-1<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    */

    for(i=1;i<=m;i++)
    {
        ansl=0;
        ansr=0;

        for(j=1;j+k-1<=n;j++)
            ansl=max(ansl, s[j][i]);

        for(j=1;j+k-1<=n;j++)
            ansr=max(ansr, s[j][m]-s[j][i]);

        ans=max(ans, ansl+ansr);
    }

    cout<<ans;
    return 0;
}
