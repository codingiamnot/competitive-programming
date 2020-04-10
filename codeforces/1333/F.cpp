#include <bits/stdc++.h>

using namespace std;
struct nr
{
    int val, dp;
    bool operator<(nr b)
    {
        return dp<b.dp;
    }
};
int n,i,j;
nr a[500005];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        a[i].dp=1;
        a[i].val=i;
    }

    for(i=2;i<=n;i++)
    {
        for(j=2*i;j<=n;j+=i)
            a[j].dp=i;
    }

    sort(a+1, a+n+1);

    for(i=2;i<=n;i++)
        cout<<a[i].dp<<' ';
    return 0;
}
