#include <iostream>

using namespace std;
int n,q,i,j,k,x,y;
long long ans,cost;
long long a[305][305];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>a[i][j];

    cin>>q;
    while(q)
    {
        q--;
        cin>>x>>y>>cost;
        a[x][y]=min(a[x][y], cost);
        a[y][x]=a[x][y];

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                a[i][j]=min(a[i][j], min(a[i][x]+a[x][y]+a[y][j], a[i][y]+a[x][y]+a[x][j]));

        ans=0;
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                ans+=a[i][j];
        cout<<ans<<' ';
    }
    return 0;
}
