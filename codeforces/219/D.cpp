#include <bits/stdc++.h>

using namespace std;
struct leg
{
    int tg, tip;
    leg(int tg, int tip)
    {
        this->tg=tg;
        this->tip=tip;
    }
};
struct nodS
{
    int dp=0;
    vector <leg> vecini;
};
int n,i,x,y,mini;
int ans[200005];
nodS nod[200005];
void dfs(int poz, int par)
{
    for(auto it : nod[poz].vecini)
    {
        if(it.tg!=par)
        {
            dfs(it.tg, poz);
            nod[poz].dp+=it.tip;
            nod[poz].dp+=nod[it.tg].dp;
        }
    }
}
void calc(int poz, int par)
{
    ans[poz] = nod[poz].dp;

    for(auto it : nod[poz].vecini)
    {
        if(it.tg!=par)
        {
            nod[poz].dp -= it.tip + nod[it.tg].dp;
            nod[it.tg].dp += (1-it.tip) + nod[poz].dp;

            calc(it.tg, poz);

            nod[it.tg].dp -= (1-it.tip) + nod[poz].dp;
            nod[poz].dp += it.tip + nod[it.tg].dp;
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(leg(y, 0));
        nod[y].vecini.push_back(leg(x, 1));
    }

    dfs(1, 0);
    calc(1, 0);

    mini=ans[1];
    for(i=2;i<=n;i++)
        mini=min(mini, ans[i]);

    cout<<mini<<'\n';
    for(i=1;i<=n;i++)
    {
        if(ans[i]==mini)
            cout<<i<<' ';
    }
    return 0;
}
