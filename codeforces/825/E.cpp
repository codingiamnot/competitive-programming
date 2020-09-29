#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    int out,ans;
    vector<int> v;
};
int n,m,i,x,y,nr;
nodS nod[100005];
set<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        nod[y].v.push_back(x);
        nod[x].out++;
    }

    for(i=1;i<=n;i++)
    {
        if(!nod[i].out)
            s.insert(i);
    }

    nr=n;
    while(!s.empty())
    {
        int p=*prev(s.end());
        s.erase(prev(s.end()));

        nod[p].ans=nr;
        nr--;

        for(int it : nod[p].v)
        {
            nod[it].out--;
            if(!nod[it].out)
                s.insert(it);
        }
    }

    for(i=1;i<=n;i++)
        cout<<nod[i].ans<<' ';
    return 0;
}
