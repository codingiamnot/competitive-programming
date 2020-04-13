#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    vector <int> vecini;
    bool ok=false,viz;
    int cnt=0;
};

int n,m,i,j,s,x,y,ans;
nodS nod[5005];
vector <int> bad;

void dfs1(int poz)
{
    nod[poz].ok=true;
    for(int it : nod[poz].vecini)
        if(!nod[it].ok)
            dfs1(it);
}
void dfs2(int poz, int par)
{
    nod[poz].viz=true;
    nod[par].cnt++;

    for(int it : nod[poz].vecini)
        if(!nod[it].viz)
            dfs2(it, par);
}
bool comp(int a, int b)
{
    return nod[a].cnt>nod[b].cnt;
}
int main()
{
    cin>>n>>m>>s;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
    }

    dfs1(s);

    for(i=1;i<=n;i++)
    {
        if(!nod[i].ok)
        {
            for(j=1;j<=n;j++)
                nod[j].viz=false;
            dfs2(i, i);
            bad.push_back(i);
        }
    }

    sort(bad.begin(), bad.end(), comp);

    for(int it : bad)
    {
        if(!nod[it].ok)
        {
            ans++;
            dfs1(it);
        }
    }

    cout<<ans;
    return 0;
}
