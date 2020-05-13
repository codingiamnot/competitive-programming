#include <bits/stdc++.h>

using namespace std;
struct poz
{
    int x,y,len;
    poz(int x, int y, int len)
    {
        this->x=x;
        this->y=y;
        this->len=len;
    }
};
char ch;
int n,m,i,j,nrq,x,y;
long long t;
int a[1005][1005];
int drum[1005][1005];
queue <poz> q;

void lee()
{
    while(!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        int len=q.front().len;
        q.pop();

        if(x<1 || x>n || y<1 || y>m)
            continue;
        if(drum[x][y]!=-1)
            continue;

        drum[x][y]=len;

        q.push(poz(x+1, y, len+1));
        q.push(poz(x-1, y, len+1));
        q.push(poz(x, y+1, len+1));
        q.push(poz(x, y-1, len+1));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>nrq;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            cin>>ch;
            a[i][j]=ch-'0';
        }

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i][j]==a[i+1][j] && i<n)
            {
                q.push(poz(i,j,0));
                continue;
            }

            if(a[i][j]==a[i][j+1] && j<m)
            {
                q.push(poz(i, j, 0));
                continue;
            }

            if(a[i][j]==a[i-1][j] && i>1)
            {
                q.push(poz(i, j, 0));
                continue;
            }

            if(a[i][j]==a[i][j-1] && j>1)
            {
                q.push(poz(i, j, 0));
                continue;
            }

        }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            drum[i][j]=-1;
    }

    lee();

    while(nrq)
    {
        nrq--;
        cin>>x>>y>>t;
        if(drum[x][y]==-1 || t<drum[x][y])
        {
            cout<<a[x][y]<<'\n';
            continue;
        }

        t-=drum[x][y];
        if(t%2)
            cout<<1-a[x][y]<<'\n';
        else
            cout<<a[x][y]<<'\n';
    }
    return 0;
}
