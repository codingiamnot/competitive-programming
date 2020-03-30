#include <bits/stdc++.h>

using namespace std;
int n,i,nr;
int a[1000006];
long long dpl[1000006];
long long dpr[1000006];
long long ans;
map <int, int> m;
vector <int> aib;
int query(int val, int st, int dr, int poz)
{
    if(st==dr && st==val)
        return aib[poz];

    int mij = (st+dr)/2;

    if(val<=mij)
        return aib[poz]+query(val, st, mij, 2*poz);
    else
        return aib[poz]+query(val, mij+1, dr, 2*poz+1);
}
void add(int stt, int drt, int st, int dr, int poz)
{
    if(stt==st && drt==dr)
    {
        aib[poz]+=1;
        return;
    }

    int mij = (st+dr)/2;

    if(drt<=mij)
    {
        add(stt, drt, st, mij, 2*poz);
        return;
    }

    if(stt>mij)
    {
        add(stt, drt, mij+1, dr, 2*poz+1);
        return;
    }

    add(stt, mij, st, mij, 2*poz);
    add(mij+1, drt, mij+1, dr, 2*poz+1);
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        m[a[i]]=1;
    }

    for(auto it : m)
    {
        nr++;
        m[it.first] = nr;
    }

    for(i=1;i<=n;i++)
        a[i]=m[a[i]];

    aib.resize(4*nr+5);

    for(i=1;i<=n;i++)
    {
        dpl[i]=query(a[i], 1, n, 1);
        add(1, a[i], 1, n, 1);
    }

    for(i=1;i<=n;i++)
        dpr[i]=a[i]+dpl[i]-i;

    for(i=1;i<=n;i++)
        ans+=dpl[i]*dpr[i];

    cout<<ans;
    return 0;
}
