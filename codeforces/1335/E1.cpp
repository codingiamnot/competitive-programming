#include <bits/stdc++.h>

using namespace std;
int t,n,i,x,j,ans,nr,pozl,pozr,maxi;
int s[200005][205];
map <int, vector<int>> m;
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        ans=1;
        maxi=0;
        for(i=1;i<=200;i++)
            m[i].clear();
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            m[x].push_back(i);
            for(j=1;j<=200;j++)
                s[i][j]=s[i-1][j];

            s[i][x]++;
        }

        for(i=1;i<=200;i++)
        {
            nr=m[i].size();
            for(x=1;2*x<=nr;x++)
            {
                pozl=m[i][x-1];
                pozr=m[i][nr-x];

                for(j=1;j<=200;j++)
                    ans=max(ans, 2*x+s[pozr-1][j]-s[pozl][j]);
            }
        }

        cout<<ans<<'\n';
    }
    return 0;
}
