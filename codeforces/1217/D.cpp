#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
struct nodS
{
    bool viz=false;
    int in,out;
    vector <pair<int, int>> vecini;
};
int n,m,x,y,nr,i,T;
int ans[5005];
nodS nod[5005];

void dfs(int poz)
{
    nod[poz].viz=true;
    nod[poz].in=++T;

    for(auto it : nod[poz].vecini)
    {
        if(!nod[it.f].viz)
            dfs(it.f);
    }

    nod[poz].out=++T;
}
void check()
{
    for(int i=1;i<=n;i++)
    {
        for(auto it : nod[i].vecini)
        {
            if(nod[i].in>nod[it.f].in && nod[i].out<nod[it.f].out)
            {
                nr=2;
                ans[it.s]=2;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back({y, i});
    }
    nr=1;
    for(i=1;i<=m;i++)
        ans[i]=1;

    for(i=1;i<=n;i++)
        if(!nod[i].viz)
            dfs(i);

    check();

    cout<<nr<<'\n';
    for(i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
