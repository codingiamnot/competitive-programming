#include <bits/stdc++.h>

using namespace std;

struct nodS
{
    bool ok;
    vector<int> v;
};

int t,n,m,i,x,y;
bool ok;
nodS nod[300005];
vector<int> ans;

void dfs(int p)
{
    nod[p].ok=true;

    for(int it : nod[p].v)
        if(!nod[it].ok)
            dfs(it);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        ans.clear();
        for(i=1;i<=n;i++)
        {
            nod[i].ok=false;
            nod[i].v.clear();
        }
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            nod[x].v.push_back(y);
            nod[y].v.push_back(x);
        }

        dfs(1);

        ok=true;
        for(i=1;i<=n;i++)
            if(!nod[i].ok)
                ok=false;

        if(!ok)
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        queue<pair<int, int>> q;
        q.push({1, 1});

        while(!q.empty())
        {
            int p=q.front().first;
            int ti=q.front().second;
            q.pop();

            if(ti)
            {
                if(!nod[p].ok)
                    continue;

                ans.push_back(p);
                nod[p].ok=false;

                for(int it : nod[p].v)
                    if(nod[it].ok)
                    {
                        nod[it].ok=false;
                        q.push({it, 0});
                    }
            }
            else
            {
                for(int it : nod[p].v)
                    if(nod[it].ok)
                        q.push({it, 1});
            }
        }

        cout<<ans.size()<<'\n';
        for(int it : ans)
            cout<<it<<' ';
        cout<<'\n';
    }
    return 0;
}
