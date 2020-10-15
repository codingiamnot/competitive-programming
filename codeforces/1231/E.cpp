#include <bits/stdc++.h>

using namespace std;
int nrt,n,i,j,ans;
bool ok;
int fr[40];
int dp[105][105];
char s[105];
char t[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>nrt;
    while(nrt)
    {
        nrt--;
        memset(fr, 0, sizeof fr);
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
            fr[s[i]-'a']++;
        }
        for(i=1;i<=n;i++)
        {
            cin>>t[i];
            fr[t[i]-'a']--;
        }

        ok=true;
        for(i=0;i<='z'-'a';i++)
            if(fr[i])
            {
                ok=false;
                break;
            }

        if(!ok)
        {
            cout<<"-1\n";
            continue;
        }

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=dp[i-1][j];
            }

        ans=n;
        for(j=1;j<=n;j++)
            ans=min(ans, n-dp[n][j]);
        cout<<ans<<'\n';
    }
    return 0;
}
