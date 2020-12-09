#include <iostream>

using namespace std;

int n,m,i,j,k;
int u[2005],v[2005],b;
int dist[205][205];
int main()
{
    cin>>n>>m;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
                dist[i][j]=1e9;

    for(i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>b;

        if(!b)
        {
            dist[u[i]][v[i]]=1;
            dist[v[i]][u[i]]=1;
        }
        else
        {
            dist[u[i]][v[i]]=1;
            dist[v[i]][u[i]]=-1;
        }
    }

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(dist[i][k]!=1e9 && dist[k][j]!=1e9 && dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];

                    if(dist[i][j]<-1e9)
                    {
                        cout<<"NO";
                        return 0;
                    }
                }

    pair<int, int> best={-1, 1};

    for(i=1;i<=n;i++)
    {
        if(dist[i][i]<0)
        {
            cout<<"NO";
            return 0;
        }

        for(j=1;j<=n;j++)
            best=max(best, {dist[i][j], i});
    }

    int rad=best.second;

    for(i=1;i<=m;i++)
    {
        if(dist[rad][u[i]] == dist[rad][v[i]])
        {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES\n";
    cout<<best.first<<'\n';
    for(i=1;i<=n;i++)
        cout<<dist[rad][i]<<' ';
    return 0;
}
