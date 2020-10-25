#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    int nr;
    long long s;
    vector<int> v;
};
int n,i,x,nr;
long long ans;
nodS nod[200005];
long long v[200005];
void dfs(int p)
{
    for(int it : nod[p].v)
    {
        dfs(it);
        nod[p].s+=nod[it].s;
        nod[p].nr+=nod[it].nr;
    }

    if(nod[p].v.empty())
    {
        nod[p].nr++;
    }

    ans=max(ans, (nod[p].s+nod[p].nr-1)/nod[p].nr);
}
int main()
{
    cin>>n;
    for(i=2;i<=n;i++)
    {
        cin>>x;
        nod[x].v.push_back(i);
    }
    for(i=1;i<=n;i++)
        cin>>nod[i].s;

    dfs(1);
    cout<<ans;
    return 0;
}
