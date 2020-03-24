#include <iostream>

using namespace std;
int n,q,i,j,tot,pierdere, ans;
int d[5005];
int dp[3][5005];
struct interS
{
    int x, y;
} a[5005];
interS inter;
interS sup(interS a, interS b)
{
    interS ans;
    ans.x=max(a.x, b.x);
    ans.y=min(a.y, b.y);

    return ans;
}
int main()
{
    cin>>n>>q;

    for(i=1;i<=q;i++)
    {
        cin>>a[i].x>>a[i].y;

        for(j=a[i].x;j<=a[i].y;j++)
            d[j]++;
    }

    for(i=1;i<=n;i++)
        if(d[i])
            tot++;

    for(i=1;i<=n;i++)
    {
        dp[1][i]=dp[1][i-1];
        dp[2][i]=dp[2][i-1];

        if(d[i]==1)
            dp[1][i]++;
        if(d[i]==2)
            dp[2][i]++;
    }

    for(i=1;i<q;i++)
        for(j=i+1;j<=q;j++)
        {
            inter =  sup(a[i], a[j]);
            pierdere = dp[1][a[i].y]-dp[1][a[i].x-1];
            pierdere += dp[1][a[j].y]-dp[1][a[j].x-1];
            if(inter.y>=inter.x)
                pierdere += dp[2][inter.y]-dp[2][inter.x-1];
            ans = max(ans, tot-pierdere);
        }

    cout<<ans;
    return 0;
}
