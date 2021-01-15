#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    int sum=0, col;
    map<int, int> *m=0;
    vector<int> v;
};

int n,m,x,y,i;
int tot, ans;
map<int, int> nr;
nodS nod[200005];

void fmerge(map<int, int> *&a, map<int, int> *&b)
{
    if(!b)
        return;

    if(!a)
    {
        swap(a, b);
        return;
    }

    if(a->size() < b->size())
        swap(a, b);

    for(auto it : *b)
        (*a)[it.first]+=it.second;
}
void dfs(int p, int par)
{
    for(int it : nod[p].v)
    {
        if(it==par)
            continue;

        dfs(it, p);

        if((*nod[it].m)[nod[p].col])
        {
            nod[it].sum++;
            tot++;
        }

        fmerge(nod[p].m, nod[it].m);
    }

    if(!nod[p].m)
        nod[p].m=new map<int, int>;

    (*nod[p].m)[nod[p].col]++;

    if(nr[nod[p].col] > (*nod[p].m)[nod[p].col])
    {
        nod[1].sum++;
        nod[p].sum--;
        tot++;
    }
}
void dfs2(int p, int par)
{
    nod[p].sum+=nod[par].sum;

    for(int it : nod[p].v)
    {
        if(it==par)
            continue;

        dfs2(it, p);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>nod[i].col;
        nr[nod[i].col]++;
    }

    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].v.push_back(y);
        nod[y].v.push_back(x);
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(i=1;i<=n;i++)
        if(nod[i].sum==tot)
            ans++;

    cout<<ans;
    return 0;
}
