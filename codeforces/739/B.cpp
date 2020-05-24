#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
struct nodS
{
    int val, dp=0;
    long long sum;
    int lift[22];
    vector <pair<int, long long>> vecini;
};
int n,i,st,dr,mij,last,poz,x,w;
nodS nod[200005];
void dfs(int poz, int par, long long sum)
{
    nod[poz].sum=sum;
    nod[poz].lift[0]=par;
    for(int b=1;b<=22;b++)
    {
        nod[poz].lift[b]=nod[nod[poz].lift[b-1]].lift[b-1];
        if(!nod[poz].lift[b])
            break;
    }

    for(auto it : nod[poz].vecini)
    {
        if(it.f!=par)
            dfs(it.f, poz, sum+it.s);
    }
}
void dfs2(int poz, int par)
{
    for(auto it : nod[poz].vecini)
    {
        if(it.f==par)
            continue;
        dfs2(it.f, poz);
        nod[poz].dp+=nod[it.f].dp;
    }
}
int anc(int poz, int k)
{
    if(!k)
        return poz;

    for(int b=0;b<=22;b++)
        if((k>>b)&1)
            return anc(nod[poz].lift[b], k-(1<<b));
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>nod[i].val;

    for(i=2;i<=n;i++)
    {
        cin>>x>>w;
        nod[x].vecini.push_back({i, w});
    }

    dfs(1, 0, 0);

    for(i=1;i<=n;i++)
    {
        st=0;
        dr=n;
        last=0;

        while(st<=dr)
        {
            mij=(st+dr)/2;
            poz=anc(i, mij);

            if(!poz)
            {
                dr=mij-1;
                continue;
            }

            if(nod[i].sum-nod[poz].sum>nod[i].val)
                dr=mij-1;
            else
            {
                last=poz;
                st=mij+1;
            }
        }

        nod[nod[i].lift[0]].dp++;
        nod[nod[last].lift[0]].dp--;
    }

    dfs2(1, 0);

    for(i=1;i<=n;i++)
        cout<<nod[i].dp<<' ';
    return 0;
}
