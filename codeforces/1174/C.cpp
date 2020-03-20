#include <bits/stdc++.h>

using namespace std;
long long n,i,j;
int nr,ans[100005];
int main()
{
    cin>>n;
    for(i=2;i<=n;i++)
    {
        if(!ans[i])
        {
            nr++;
            ans[i]=nr;

            for(j=i*i;j<=n;j+=i)
            {
                ans[j]=nr;
            }
        }
    }
    for(i=2;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}
