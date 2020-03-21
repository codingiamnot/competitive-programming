#include <bits/stdc++.h>

using namespace std;
int n,m,i,x,y,cost;
stack <int> ans;
struct nodS
{
    int drum, parrent;
    vector <pair<int, int>> vecini;
} nod[100005];
struct drum
{
    int len,parrent,poz;
    drum(int poz, int len, int parrent)
    {
        this->len=len;
        this->parrent=parrent;
        this->poz=poz;
    }
    bool operator<(drum b) const
    {
        return len<b.len;
    }
};
void djisktra(int start)
{
    multiset <drum> s;
    s.insert(drum(start, 0, 0));
    while(nod[n].drum==1e9 && !s.empty())
    {
        auto now = *s.begin();
        s.erase(s.begin());

        if(nod[now.poz].drum!=1e9)
            continue;

        nod[now.poz].drum=now.len;
        nod[now.poz].parrent=now.parrent;

        for(auto it : nod[now.poz].vecini)
        {
            if(nod[it.first].drum==1e9)
                s.insert(drum(it.first, now.len+it.second, now.poz));
        }
    }
}
void reconstruct(int poz)
{
    ans.push(poz);

    if(poz!=1)
        reconstruct(nod[poz].parrent);
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        nod[i].drum=1e9;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>cost;
        nod[x].vecini.push_back({y, cost});
        nod[y].vecini.push_back({x, cost});
    }

    djisktra(1);

    if(nod[n].drum==1e9)
    {
        cout<<-1;
        return 0;
    }
    reconstruct(n);

    while(!ans.empty())
    {
        cout<<ans.top()<<' ';
        ans.pop();
    }
    return 0;
}
