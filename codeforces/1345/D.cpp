#include <iostream>

using namespace std;
int n,m,i,j,ans;
char ch;
int a[1005][1005];
int viz[1005][1005];
int okl[1005];
int okc[1005];
bool ok;
void flood(int i, int j)
{
    if(viz[i][j])
        return;
    if(!a[i][j])
        return;

    viz[i][j]=1;
    flood(i-1, j);
    flood(i+1, j);
    flood(i, j-1);
    flood(i, j+1);
}
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            cin>>ch;
            if(ch=='#')
                a[i][j]=1;
        }

    for(i=1; i<=n; i++)
    {
        ok=true;
        for(j=1; j<=m; j++)
        {
            if(a[i][j] && !ok)
            {
                cout<<-1;
                return 0;
            }
            if(!a[i][j] && a[i][j-1])
                ok=false;
        }
    }

    for(j=1; j<=m; j++)
    {
        ok=true;
        for(i=1; i<=n; i++)
        {
            if(a[i][j] && !ok)
            {
                cout<<-1;
                return 0;
            }
            if(!a[i][j] && a[i-1][j])
                ok=false;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            if(a[i][j])
        {
            okl[i]=true;
            okc[j]=true;
        }
    }

    for(i=1;i<=n;i++)
    {
        if(okl[i])
            continue;
        ok=false;
        for(j=1;j<=m;j++)
        {
            if(!okc[j])
                ok=true;
        }
        if(!ok)
        {
            cout<<-1;
            return 0;
        }
    }

    for(j=1;j<=m;j++)
    {
        if(okc[j])
            continue;
        ok=false;
        for(i=1;i<=n;i++)
        {
            if(!okl[i])
                ok=true;
        }
        if(!ok)
        {
            cout<<-1;
            return 0;
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(!viz[i][j] && a[i][j])
            {
                ans++;
                flood(i, j);
            }
        }
    }

    cout<<ans;
    return 0;
}
