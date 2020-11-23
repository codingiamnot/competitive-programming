#include <bits/stdc++.h>

using namespace std;

int t,n,m,x,i,j;
int fr[205];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        memset(fr, 0, sizeof fr);
        cin>>n>>m;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                cin>>x;
                fr[i+j]^=x;
            }

        bool ok=false;
        for(i=1;i<=n+m;i++)
        {
            if(fr[i])
                ok=true;
        }

        if(ok)
            cout<<"Ashish\n";
        else
            cout<<"Jeel\n";
    }

    return 0;
}
