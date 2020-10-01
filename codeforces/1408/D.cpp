#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
struct pct
{
    int x, y;
};
int n,m,i,j,x,y,nval,ans;
int val[1000005];
int nr[2005];
pct v[2005];
vector<pair<int, int>> act[1000005];
multiset<int> s;
int main()
{
    cin>>n>>m;
    s.insert(0);
    for(i=0;i<=1e6+1;i++)
        val[i]=-1;

    for(i=1;i<=n;i++)
        cin>>v[i].x>>v[i].y;

    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        val[x]=max(val[x], y);
    }

    for(i=1e6;i>=0;i--)
        val[i]=max(val[i+1], val[i]);

    for(i=1;i<=1e6+1;i++)
    {
        if(val[i]<val[i-1])
        {
            for(j=1;j<=n;j++)
            {
                if(i>v[j].x)
                    act[i-v[j].x].push_back({j, val[i]});
            }
        }
    }

    for(i=1;i<=n;i++)
    {
        nr[i]=max(0, val[v[i].x]-v[i].y+1);
        s.insert(nr[i]);
    }

    ans=*prev(s.end());

    for(i=1;i<=1e6+1;i++)
    {
        for(auto it : act[i])
        {
            j=it.f;
            nval=it.s;

            s.erase(s.find(nr[j]));
            nr[j]=max(0, nval-v[j].y+1);
            s.insert(nr[j]);
        }
        ans=min(ans, *prev(s.end())+i);
    }

    cout<<ans<<'\n';
    return 0;
}
