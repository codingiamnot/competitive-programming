#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    vector<int> v;
};

int t,n,x,y,i,ans;
nodS nod[200005];

int dfs(int p, int par)
{
    if(nod[p].v.size()==1 && par)
        return 1;

    vector<int> v;
    for(int it : nod[p].v)
    {
        if(it==par)
            continue;

        v.push_back(dfs(it, p));
    }

    sort(v.begin(), v.end());

    if(v.size()>1)
    {
        if(!par)
        {
            ans=max(ans, v.back());
            ans=max(ans, v[v.size()-2]+1);
        }
        else
        {
            ans=max(ans, v.back()+1);
        }
    }
    else
        ans=max(ans, v[0]);

    return v[0]+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=1;i<=n;i++)
            nod[i].v.clear();

        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            nod[x].v.push_back(y);
            nod[y].v.push_back(x);
        }

        ans=0;
        dfs(1, 0);

        cout<<ans<<'\n';
    }
    return 0;
}
