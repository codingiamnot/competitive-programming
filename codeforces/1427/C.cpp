#include <bits/stdc++.h>

using namespace std;
struct pos
{
    int x=0, y=0, t=0;
};
int n,r,p,maxi,i,j,ans;
int dp[100005];
pos v[100005];
int dist(int i, int j)
{
    return abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
}
int main()
{
    cin>>r>>n;
    p=-1;
    maxi=-1e9;
    v[0].x=1;
    v[0].y=1;

    for(i=1;i<=n;i++)
    {
        cin>>v[i].t>>v[i].x>>v[i].y;
        while(v[p+1].t+2*r<=v[i].t)
        {
            p++;
            maxi=max(maxi, dp[p]);
        }

        dp[i]=maxi+1;
        for(j=p+1;j<i;j++)
        {
            if(v[j].t+dist(j, i)<=v[i].t)
                dp[i]=max(dp[i], dp[j]+1);
        }
    }

    for(i=1;i<=n;i++)
        ans=max(ans, dp[i]);
    cout<<ans;
    return 0;
}
