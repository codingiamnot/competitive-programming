#include <iostream>

using namespace std;
int n,m,k,i,j,x,y;
int main()
{
    cin>>n>>m>>k;
    for(i=1;i<=k;i++)
        cin>>x>>y;

    for(i=1;i<=k;i++)
        cin>>x>>y;

    cout<<n+m+n*m-3<<'\n';

    for(i=1;i<n;i++)
        cout<<'U';
    for(i=1;i<m;i++)
        cout<<'L';

    for(i=1;i<=m;i++)
    {
        if(i%2)
        {
            for(j=1;j<n;j++)
                cout<<'D';
        }
        else
        {
            for(j=1;j<n;j++)
                cout<<'U';
        }

        if(i!=m)
            cout<<'R';
    }
    return 0;
}
