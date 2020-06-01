#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    long long a,b,c,bal,cnt;
    vector <int> vecini;
};
int n,i,x,y;
long long ans;
bool ok;
nodS nod[200005];
void dfs(int poz, int par, long long mini)
{
    mini=min(mini, nod[poz].a);
    nod[poz].a=mini;
    for(int it : nod[poz].vecini)
    {
        if(it!=par)
            dfs(it, poz, mini);
    }
}
void dfs2(int poz, int par)
{
    if(nod[poz].b!=nod[poz].c)
        nod[poz].cnt=1;
    nod[poz].bal=nod[poz].b-nod[poz].c;
    for(int it : nod[poz].vecini)
    {
        if(it!=par)
        {
            dfs2(it, poz);
            nod[poz].bal+=nod[it].bal;
            nod[poz].cnt+=abs(nod[it].bal);
        }
    }
    ans+=(nod[poz].cnt-abs(nod[poz].bal))*nod[poz].a;
}
int main()
{
    cin>>n;
    ok=true;
    for(i=1;i<=n;i++)
    {
        cin>>nod[i].a>>nod[i].b>>nod[i].c;
    }
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }


    dfs(1, 0, 1e9);
    dfs2(1, 0);

    if(nod[1].bal)
    {
        cout<<-1;
        return 0;
    }

    cout<<ans;
    return 0;
}
