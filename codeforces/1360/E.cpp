#include <iostream>

using namespace std;
int t,n,i,j;
char ch;
bool ok;
int a[55][55];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(i=0;i<=n+1;i++)
            for(j=0;j<=n+1;j++)
                a[i][j]=1;

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
        {
            cin>>ch;
            a[i][j]=ch-'0';
        }

        ok=true;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][j] && !a[i+1][j] && !a[i][j+1])
        {
            ok=false;
            break;
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
