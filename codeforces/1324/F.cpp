#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    int val, dp;
    vector <int> vecini;
};
int n,i,x,y;
vector <int> ans;
vector <nodS> nod;
void calc(int poz, int parrent)
{
    nod[poz].dp=nod[poz].val;
    for(auto it : nod[poz].vecini)
    {
        if(it!=parrent)
        {
            calc(it, poz);
            if(nod[it].dp>0)
                nod[poz].dp+=nod[it].dp;
        }
    }
}
void misc(int poz, int parrent)
{
    ans[poz]=nod[poz].dp;
    for(auto it : nod[poz].vecini)
    {
        if(it!=parrent)
        {
            nod[poz].dp-=max(0, nod[it].dp);
            nod[it].dp+=max(0, nod[poz].dp);
            misc(it, poz);
            nod[it].dp-=max(0, nod[poz].dp);
            nod[poz].dp+=max(0, nod[it].dp);
        }
    }
}
int main()
{
    cin>>n;
    nod.resize(n+1);
    ans.resize(n+1);
    for(i=1;i<=n;i++)
    {
        cin>>nod[i].val;
        if(!nod[i].val)
            nod[i].val--;
    }


    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }

    calc(1, 0);
    misc(1, 0);

    for(i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
