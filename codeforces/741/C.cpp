#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    bool viz;
    int col;
    vector<int> v;
};

int n,i,x,y;
nodS nod[200005];
vector<pair<int, int>> v;

void dfs(int p, int col)
{
    nod[p].col=col;
    nod[p].viz=true;

    for(int it : nod[p].v)
    {
        if(!nod[it].viz)
            dfs(it, col^1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        v.push_back({x, y});
        nod[x].v.push_back(y);
        nod[y].v.push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        nod[2*i].v.push_back(2*i+1);
        nod[2*i+1].v.push_back(2*i);
    }

    for(i=1;i<=2*n;i++)
        if(!nod[i].viz)
            dfs(i, 0);

    for(auto it : v)
        cout<<nod[it.first].col+1<<' '<<nod[it.second].col+1<<'\n';
    return 0;
}
