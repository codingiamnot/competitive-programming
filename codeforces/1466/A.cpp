#include <bits/stdc++.h>

using namespace std;

int t,n,ans,i,j;
int a[55];
map<int, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        ans=0;
        m.clear();

        for(i=1;i<=n;i++)
            cin>>a[i];

        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
            {
                if(m[a[j]-a[i]]==0)
                {
                    m[a[j]-a[i]]=1;
                    ans++;
                }
            }

        cout<<ans<<'\n';
    }
    return 0;
}
