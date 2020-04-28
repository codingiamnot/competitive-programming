#include <bits/stdc++.h>

using namespace std;
struct nod
{
    long long mini,sum;
};
int n,i,poz;
int ans[200005];
long long x;
vector<nod> aib;
void add(long long val, int stt, int drt, int st, int dr, int poz)
{
    if(stt==st && drt==dr)
    {
        aib[poz].sum+=val;
        aib[poz].mini+=val;
        return;
    }

    int mij=(st+dr)/2;
    if(drt<=mij)
        add(val, stt, drt, st, mij, 2*poz);
    else
    {
        if(stt>mij)
            add(val, stt, drt, mij+1, dr, 2*poz+1);
        else
        {
            add(val, stt, mij, st, mij, 2*poz);
            add(val, mij+1, drt, mij+1, dr, 2*poz+1);
        }
    }

    aib[poz].mini=min(aib[2*poz].mini, aib[2*poz+1].mini)+aib[poz].sum;
}
int lastzero(long long sum, int st, int dr, int poz)
{
    if(aib[poz].mini+sum>0)
        return 0;

    if(st==dr)
        return st;

    int mij=(st+dr)/2;
    int ans=lastzero(sum+aib[poz].sum, mij+1, dr, 2*poz+1);
    if(ans)
        return ans;
    return lastzero(sum+aib[poz].sum, st, mij, 2*poz);
}
int main()
{
    cin>>n;
    aib.resize(4*n+4);
    for(i=1;i<=n;i++)
    {
        cin>>x;
        add(x, i, i, 1, n, 1);
    }
    for(i=1;i<=n;i++)
    {
        poz=lastzero(0, 1, n, 1);
        add(1e18, poz, poz, 1, n, 1);
        ans[poz]=i;
        if(poz<n)
            add(-i, poz+1, n, 1, n, 1);
    }

    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
