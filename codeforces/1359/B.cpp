#include <iostream>

using namespace std;
int t,n,m,nr,i,j;
long long ans,x,y;
char ch;
void upd()
{
    if(nr%2)
        ans+=(nr/2)*y+x;
    else
        ans+=(nr/2)*y;
    nr=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t)
    {
        t--;
        ans=0;
        cin>>n>>m>>x>>y;
        y=min(y, 2*x);

        for(i=1;i<=n;i++)
        {
            nr=0;
            for(j=1;j<=m;j++)
            {
                cin>>ch;
                if(ch=='.')
                    nr++;
                else
                    upd();
            }
            upd();
        }
        cout<<ans<<'\n';
    }
    return 0;
}
