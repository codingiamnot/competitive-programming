#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    int mex;
    vector <int> vecini;
};
struct poz
{
    int p,mex;
    poz(int mex, int p)
    {
        this->mex=mex;
        this->p=p;
    }
    bool operator<(poz b) const
    {
        return mex<b.mex;
    }
};
int n,m,i,x,y;
nodS nod[500005];
vector <poz> v;
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }
    for(i=1;i<=n;i++)
        nod[i].mex=1;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        v.push_back(poz(x, i));
    }
    sort(v.begin(), v.end());

    for(auto it : v)
    {
        if(nod[it.p].mex!=it.mex)
        {
            cout<<-1;
            return 0;
        }
        for(int i : nod[it.p].vecini)
        {
            if(nod[i].mex==it.mex)
                nod[i].mex++;
        }
    }

    for(auto it : v)
    {
        cout<<it.p<<' ';
    }
    return 0;
}
