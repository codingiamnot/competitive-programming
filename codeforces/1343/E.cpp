#include <bits/stdc++.h>

using namespace std;
struct nodS
{
    vector <int> vecini;
    int len[3];
};
int t,n,m,a,b,c,i,x,y;
int p[200005];
long long nans,ans;
long long s[200005];
nodS nod[200005];
void bfs(int start, int dim)
{
    queue <pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty())
    {
        int poz=q.front().first;
        int len=q.front().second;
        q.pop();

        if(nod[poz].len[dim]!=-1)
            continue;

        nod[poz].len[dim]=len;

        for(int it : nod[poz].vecini)
        {
            if(nod[it].len[dim]==-1)
                q.push({it, len+1});
        }
    }
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m>>a>>b>>c;

        for(i=1;i<=n;i++)
        {
            nod[i].vecini.clear();
            nod[i].len[0]=-1;
            nod[i].len[1]=-1;
            nod[i].len[2]=-1;
        }

        for(i=1;i<=m;i++)
            cin>>p[i];
        sort(p+1, p+m+1);
        for(i=1;i<=m;i++)
            s[i]=s[i-1]+p[i];

        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            nod[x].vecini.push_back(y);
            nod[y].vecini.push_back(x);
        }

        ans=2*s[m];
        bfs(b, 0);
        bfs(a, 1);
        bfs(c, 2);

        for(i=1;i<=n;i++)
        {
            if(nod[i].len[0]+nod[i].len[1]+nod[i].len[2]>m)
                continue;
            nans=s[nod[i].len[0]+nod[i].len[1]+nod[i].len[2]];
            nans+=s[nod[i].len[0]];
            ans=min(ans, nans);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
