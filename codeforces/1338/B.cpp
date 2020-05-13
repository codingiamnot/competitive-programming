#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    vector<int> vecini;
    bool leafpar=false;
};
nodS nod[100005];
int n,i,x,y,nri,nrp,root,nrleafpar;
int mini,maxi;
void dfs(int poz, int d, int par)
{
    if(nod[poz].vecini.size()==1)
    {
        if(d%2)
            nri++;
        else
            nrp++;

        return;
    }

    for(int it : nod[poz].vecini)
    {
        if(it==par)
            continue;

        if(nod[it].vecini.size()>1)
            maxi++;
        if(nod[it].vecini.size()==1 && !nod[poz].leafpar)
        {
            maxi++;
            nod[poz].leafpar=true;
        }
        dfs(it, d+1, poz);
    }
}
int main()
{
    cin>>n;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        if(nod[i].vecini.size()>1)
        {
            root=i;
            break;
        }
    }

    dfs(root, 0, 0);

    for(i=1;i<=n;i++)
    {
        if(nod[i].leafpar)
            nrleafpar++;
    }

    if(!nrp || !nri)
        mini=1;
    else
        mini=3;

    cout<<mini<<' '<<maxi;
    return 0;
}
