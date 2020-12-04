#include <bits/stdc++.h>

using namespace std;

long long t,x,i,j;
long long dp[102];
vector<int> ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[1]=2;
    for(i=2;i<=58;i++)
        dp[i]=2*dp[i-1]+2;

    cin>>t;
    while(t)
    {
        t--;
        cin>>x;

        if(x%2)
        {
            cout<<"-1\n";
            continue;
        }
        ans.clear();

        for(i=58;i>=1;i--)
        {
            while(x>=dp[i])
            {
                x-=dp[i];

                ans.push_back(1);
                for(j=1;j<i;j++)
                    ans.push_back(0);
            }
        }

        cout<<ans.size()<<'\n';
        for(int it : ans)
            cout<<it<<' ';
        cout<<'\n';
    }
    return 0;
}
