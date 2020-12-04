#include <bits/stdc++.h>

using namespace std;

int t,n,i,j;
char s[2005];
vector<pair<int, int>> v[14];
int ans,maxi,mini,maxj,minj,maxx,maxy;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        for(i=0;i<=9;i++)
            v[i].clear();

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>s;
            for(j=1;j<=n;j++)
            {
                v[s[j-1]-'0'].push_back({i, j});
            }
        }

        for(i=0;i<=9;i++)
        {
            ans=0;
            maxi=0;
            maxj=0;
            mini=n+1;
            minj=n+1;

            for(auto it : v[i])
            {
                maxi=max(maxi, it.first);
                maxj=max(maxj, it.second);

                mini=min(mini, it.first);
                minj=min(minj, it.second);
            }

            for(auto it : v[i])
            {
                maxx=max(it.first-1, n-it.first);
                maxy=max(it.second-1, n-it.second);

                ans=max(ans, (maxi-it.first)*maxy);
                ans=max(ans, (it.first-mini)*maxy);
                ans=max(ans, (maxj-it.second)*maxx);
                ans=max(ans, (it.second-minj)*maxx);
            }

            cout<<ans<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
