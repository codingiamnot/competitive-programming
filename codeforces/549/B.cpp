#include <bits/stdc++.h>

using namespace std;
int n,i,j;
bool ok;
char ch;
vector<int> adj[105];
vector<int> ans;
int s[105];
int nr[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>ch;
            if(j==i)
            {
                adj[i].push_back(i);
                continue;
            }

            if(ch=='1')
                adj[i].push_back(j);
        }
    }
    for(i=1;i<=n;i++)
        cin>>s[i];

    ok=false;
    while(!ok)
    {
        ok=true;
        vector<int> v;
        for(i=1;i<=n;i++)
        {
            if(nr[i]==s[i])
            {
                v.push_back(i);
                ok=false;
            }

        }

        for(int it : v)
        {
            ans.push_back(it);
            for(int it2 : adj[it])
                nr[it2]++;
        }
    }

    cout<<ans.size()<<'\n';
    for(int it : ans)
        cout<<it<<' ';
    return 0;
}
