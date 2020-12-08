#include <bits/stdc++.h>

using namespace std;

struct pct
{
    long long x,y;
};

int t;
long long ans;
long long aux[10];
pct a[10];
int v[10];

long long calc(pct a, pct b, pct c, pct d, long long k)
{
    long long ans=0;

    aux[1]=a.x;
    aux[2]=b.x;
    aux[3]=c.x+k;
    aux[4]=d.x+k;
    sort(aux+1, aux+5);
    ans+=aux[2]-aux[1];
    ans+=aux[3]-aux[2];
    ans+=aux[4]-aux[2];

    aux[1]=a.y;
    aux[2]=b.y+k;
    aux[3]=c.y+k;
    aux[4]=d.y;
    sort(aux+1, aux+5);
    ans+=aux[2]-aux[1];
    ans+=aux[3]-aux[2];
    ans+=aux[4]-aux[2];

    return ans;
}
long long solve(pct a, pct b, pct c, pct d)
{
    int st=0, dr=1e9, mij1, mij2;
    long long val1, val2;
    long long ans=1e18;

    while(st<=dr)
    {
        mij1=st+(dr-st)/3;
        mij2=dr-(dr-st)/3;
        val1=calc(a, b, c, d, mij1);
        val2=calc(a, b, c, d, mij2);

        ans=min(ans, val1);
        ans=min(ans, val2);

        if(val1<val2)
            dr=mij2-1;
        else
            st=mij1+1;
    }

    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>a[1].x>>a[1].y;
        cin>>a[2].x>>a[2].y;
        cin>>a[3].x>>a[3].y;
        cin>>a[4].x>>a[4].y;

        ans=1e18;

        v[1]=1;
        v[2]=2;
        v[3]=3;
        v[4]=4;

        do
        {
            ans=min(ans, solve(a[v[1]], a[v[2]], a[v[3]], a[v[4]]));
        }
        while(next_permutation(v+1, v+5));

        cout<<ans<<'\n';
    }
    return 0;
}
