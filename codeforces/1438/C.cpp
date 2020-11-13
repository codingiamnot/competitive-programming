#include <iostream>

using namespace std;
int t,n,m,i,j,x;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                cin>>x;
                if(x%2 != (i+j)%2)
                    x++;

                cout<<x<<' ';
            }
            cout<<'\n';
        }

    }
    return 0;
}
