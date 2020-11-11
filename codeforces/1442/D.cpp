#include <bits/stdc++.h>

using namespace std;

long long n,k,i,j,x,ans;
long long nr[3005];
long long sum[3005];
vector<long long> v[3005];

void add(long long val, long long cost, long long dp[])
{
    for(int i=k;i>=1;i--)
    {
        if(i>=cost)
            dp[i]=max(dp[i], dp[i-cost]+val);
    }
    for(int i=1;i<=k;i++)
        dp[i]=max(dp[i], dp[i-1]);
}
void cpy(long long a[], long long b[])
{
    for(int i=0;i<=k;i++)
        a[i]=b[i];
}
void solve(int i, long long dp[])
{
    long long sum=0;
    for(int j=0;j<nr[i];j++)
    {
        sum+=v[i][j];

        if(k-j-1>=0)
            ans=max(ans, dp[k-j-1]+sum);
    }
}
void calc(int l, int r, long long dp[])
{
    if(l==r)
    {
        solve(l, dp);
        return;
    }

    long long dp2[3005];
    int mij=(l+r)/2;

    cpy(dp2, dp);
    for(int i=mij+1;i<=r;i++)
        add(sum[i], nr[i], dp2);
    calc(l, mij, dp2);

    cpy(dp2, dp);
    for(int i=l;i<=mij;i++)
        add(sum[i], nr[i], dp2);
    calc(mij+1, r, dp2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;

    for(i=1;i<=n;i++)
    {
        cin>>nr[i];
        for(j=1;j<=nr[i];j++)
        {
            cin>>x;
            sum[i]+=x;
            v[i].push_back(x);
        }
    }

    ans=0;
    long long dp[3005];
    memset(dp, 0, sizeof dp);

    calc(1, n, dp);

    cout<<ans;
    return 0;
}
