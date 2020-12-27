#include <iostream>

using namespace std;

int t,n,m,i,x,y,ans;
int dsu[100005];

int dsu_par(int x)
{
    if(dsu[x]!=x)
        dsu[x]=dsu_par(dsu[x]);

    return dsu[x];
}
void dsu_merge(int x, int y)
{
    x=dsu_par(x);
    y=dsu_par(y);

    if(x==y)
    {
        ans++;
        return;
    }

    dsu[x]=y;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;

        ans=0;
        for(i=1;i<=n;i++)
            dsu[i]=i;

        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            if(x==y)
                continue;

            ans++;
            dsu_merge(x, y);
        }

        cout<<ans<<'\n';
    }
    return 0;
}
