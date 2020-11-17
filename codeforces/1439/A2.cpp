#include <bits/stdc++.h>

using namespace std;
struct pos
{
    pair<int, int> a, b, c;
    pos(pair<int, int> a, pair<int, int> b, pair<int, int> c)
    {
        this->a=a;
        this->b=b;
        this->c=c;
    }
};

int t,n,m,i,j,c1,c2;
char ch;
int a[105][105];
vector<pos> ans;
vector<pair<int, int>> v0,v1;

void solve(vector<pair<int, int>> &v0, vector<pair<int, int>> &v1)
{
    if(v1.empty())
        return;

    if(v1.size()==3)
    {
        ans.push_back(pos(v1[0], v1[1], v1[2]));
        return;
    }
    if(v1.size()==4)
    {
        ans.push_back(pos(v1[1], v1[2], v1[3]));
        v0.push_back(v1[1]);
        v0.push_back(v1[2]);
        v0.push_back(v1[3]);
        v1.pop_back();
        v1.pop_back();
        v1.pop_back();
        solve(v0, v1);
        return;
    }

    auto aux=v1.back();
    v1.pop_back();

    if(v0.empty())
    {
        while(true)
        {

        }
    }
    auto aux2=v0.back();
    v0.pop_back();

    if(v0.empty())
    {
        while(true)
        {

        }
    }
    auto aux3=v0.back();
    v0.pop_back();

    ans.push_back(pos(aux, aux2, aux3));
    v0.push_back(aux);
    v1.push_back(aux2);
    v1.push_back(aux3);
    solve(v0, v1);
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
            for(j=1;j<=m;j++)
            {
                cin>>ch;
                a[i][j]=ch-'0';
            }

        for(i=1;i+2<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(!a[i][j])
                    continue;

                c1=j;

                if(j<m)
                    c2=j+1;
                else
                    c2=j-1;

                a[i][j]^=1;
                a[i+1][c1]^=1;
                a[i+1][c2]^=1;

                ans.push_back(pos({i, j}, {i+1, c1}, {i+1, c2}));
            }
        }

        for(j=1;j+2<=m;j++)
        {
            if(a[n-1][j] && a[n][j])
            {
                ans.push_back(pos({n-1, j}, {n, j}, {n-1, j+1}));
                a[n-1][j]^=1;
                a[n][j]^=1;
                a[n-1][j+1]^=1;
            }
            else if(a[n-1][j])
            {
                ans.push_back(pos({n-1, j}, {n-1, j+1}, {n, j+1}));
                a[n-1][j]^=1;
                a[n-1][j+1]^=1;
                a[n][j+1]^=1;
            }
            else if(a[n][j])
            {
                ans.push_back(pos({n, j}, {n-1, j+1}, {n, j+1}));
                a[n][j]^=1;
                a[n-1][j+1]^=1;
                a[n][j+1]^=1;
            }
        }

        v0.clear();
        v1.clear();

        for(i=n-1;i<=n;i++)
            for(j=m-1;j<=m;j++)
            {
                if(a[i][j])
                    v1.push_back({i, j});
                else
                    v0.push_back({i, j});
            }

        solve(v0, v1);

        cout<<ans.size()<<'\n';
        for(auto it : ans)
        {
            cout<<it.a.first<<' '<<it.a.second<<' ';
            cout<<it.b.first<<' '<<it.b.second<<' ';
            cout<<it.c.first<<' '<<it.c.second<<'\n';
        }
    }
    return 0;
}
