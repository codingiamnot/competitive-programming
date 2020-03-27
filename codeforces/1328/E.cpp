#include <bits/stdc++.h>

using namespace std;
int n,m,x,y,i,k,T;
int v[200005];
bool ok;
struct nodS
{
    int tin, tout, par;
    vector <int> vecini;
} nod[200005];
void dfs(int poz, int par)
{
    nod[poz].tin = T++;
    nod[poz].par = par;
    for(auto it : nod[poz].vecini)
    {
        if(it==par)
            continue;
        dfs(it, poz);
    }
    nod[poz].tout = T++;
}
bool comp(int a, int b)
{
    return nod[a].tin<nod[b].tin;
}
bool apar(int a, int b)
{
    return (nod[b].tin>=nod[a].tin && nod[b].tout<=nod[a].tout);
}
int main()
{
    cin>>n>>m;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }
    dfs(1, 0);

    while(m)
    {
        m--;
        ok=true;
        cin>>k;
        for(i=1;i<=k;i++)
        {
            cin>>x;
            if(x!=1)
                x=nod[x].par;

            v[i]=x;
        }

        sort(v+1, v+k+1, comp);

        for(i=1;i<k;i++)
        {
            if(!apar(v[i], v[i+1]))
                ok=false;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
