#include <bits/stdc++.h>

using namespace std;
int t,n,m,i,j;
int ans[105][105];
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                ans[i][j]=0;

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
        {
            if(abs(i-j)%2==0)
                ans[i][j]=1;
        }

        if(n%2==0 || m%2==0)
        {
            if(n%2==0)
                ans[n][1]=1;
            else
                ans[1][m]=1;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(ans[i][j])
                    cout<<'B';
                else
                    cout<<'W';
            }
            cout<<'\n';
        }
    }
    return 0;
}
