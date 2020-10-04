#include <bits/stdc++.h>

using namespace std;
long long t,n,m,i,j,ni,nj,ans;
long long a[105][105];
long long calc2(long long a, long long b)
{
    return abs(a-b);
}
long long calc4(long long a, long long b, long long c, long long d)
{
    vector<long long> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(), v.end());

    long long ans=v[3]-v[2]+v[2]-v[1]+v[2]-v[0];
    return ans;
}
int main()
{
    cin>>t;
    while(t)
    {
        t--;
        cin>>n>>m;
        ans=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                cin>>a[i][j];

        for(i=1;i<=n-i+1;i++)
            for(j=1;j<=m-j+1;j++)
            {
                ni=n-i+1;
                nj=m-j+1;

                if(ni==i)
                {
                    if(nj==j)
                        continue;

                    ans+=calc2(a[i][j], a[i][nj]);
                }
                else if(nj==j)
                {
                    ans+=calc2(a[i][j], a[ni][j]);
                }
                else
                    ans+=calc4(a[i][j], a[ni][j], a[i][nj], a[ni][nj]);
            }

            cout<<ans<<'\n';
    }
    return 0;
}
