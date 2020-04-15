#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    vector <int> vecini;
    long long d, cop;
    bool operator<(nodS b) const
    {
        return d-cop>b.d-b.cop;
    }
};
long long n,k,i,x,y;
long long ans;
nodS nod[200005];
void calc(int poz, int par)
{
    nod[poz].d=nod[par].d+1;

    for(auto it : nod[poz].vecini)
    {
        if(it!=par)
        {
            calc(it, poz);
            nod[poz].cop+=nod[it].cop+1;
        }
    }
}
int main()
{
    cin>>n>>k;
    for(i=1;i<n;i++)
    {
        cin>>x>>y;
        nod[x].vecini.push_back(y);
        nod[y].vecini.push_back(x);
    }

    nod[0].d=-1;
    calc(1, 0);

    sort(nod+1, nod+n+1);

    for(i=1;i<=k;i++)
        ans+=nod[i].d-nod[i].cop;

    cout<<ans;
    return 0;
}
