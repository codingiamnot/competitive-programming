#include <iostream>

using namespace std;

const int N=(1<<22)+5;
const int S=2*N;

int n,m,i,x,ans;
bool ok[N];
bool viz[S];

void dfs(int x)
{
    //cout<<x<<' ';
    viz[x]=true;

    if(x<(1<<n))
    {
        int id=x+(1<<n);

        if(!viz[id])
            dfs(id);
    }
    else
    {
        x-=(1<<n);

        for(int b=0;b<n;b++)
        {
            int id=(x|(1<<b))+(1<<n);

            if(!viz[id])
                dfs(id);
        }

        int id=(1<<n)-1-x;
        if(!viz[id] && ok[id])
            dfs(id);
    }
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>x;
        ok[x]=true;
    }

    for(i=0;i<(1<<n);i++)
    {
        if(!viz[i] && ok[i])
        {
            ans++;
            //cout<<'\n';
            dfs(i);
        }
    }

    //cout<<'\n';
    cout<<ans;
    return 0;
}
