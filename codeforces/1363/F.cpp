#include <iostream>

using namespace std;
bool ok;
int q,n,i,j;
int dp[2005][2005];
int fr[2][2005][30];
char s[2005],t[2005];
int main()
{
    cin>>q;
    while(q)
    {
        q--;
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>s[i];
        for(i=1;i<=n;i++)
            cin>>t[i];

        for(i=0;i<=26;i++)
            fr[0][n+1][j]=fr[1][n+1][j]=0;

        for(i=n;i>=1;i--)
        {
            for(j=0;j<=26;j++)
            {
                fr[0][i][j]=fr[0][i+1][j];
                fr[1][i][j]=fr[1][i+1][j];
            }
            fr[0][i][s[i]-'a']++;
            fr[1][i][t[i]-'a']++;
        }

        ok=true;
        for(j=0;j<=26;j++)
            if(fr[0][1][j]!=fr[1][1][j])
                ok=false;

        if(!ok)
        {
            cout<<"-1\n";
            continue;
        }

        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                dp[i][j]=1e6;
                if(fr[0][i+1][t[j]-'a']>fr[1][j+1][t[j]-'a'])
                    dp[i][j]=min(dp[i][j], dp[i][j-1]);

                if(s[i]==t[j])
                    dp[i][j]=min(dp[i][j], dp[i-1][j-1]);

                dp[i][j]=min(dp[i][j], dp[i-1][j]+1);

            }
        cout<<dp[n][n]<<'\n';
    }
    return 0;
}
